/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:36:43 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 15:15:43 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_min(t_list *lst, int n)
{
	t_list	*node;
	int		max;

	node = lst;
	max = *lst->content;
	while (node)
	{
		if (*node->content < max)
			max = *node->content;
		node = node->next;
	}
	node = lst;
	if (max > n)
		return (get_max(lst, max));
	while (node)
	{
		if (*node->content > max && *node->content < n)
			max = *node->content;
		node = node->next;
	}
	return (max);
}

static int	count_instruct_a(t_list *node, t_list *lst_b, int m)
{
	t_list	*node_b;
	int		i;
	int		n;
	int		max;

	i = 0;
	n = *node->content;
	max = max_min(lst_b, n);
	node_b = lst_b;
	while (max != *node_b->content)
	{
		i++;
		node_b = node_b->next;
	}
	if (i > ft_lstsize(lst_b) / 2)
		i = i - ft_lstsize(lst_b);
	if (i < 0)
		i *= -1;
	return (i + m);
}

static t_list	*search_a(t_list *lst_a, t_list *lst_b)
{
	t_list	*node;
	t_list	*min_node;
	int		min;

	min_node = lst_a;
	node = lst_a;
	min = count_instruct_a(lst_a, lst_b, 0);
	while (node)
	{
		if (min > count_instruct_a(node, lst_b, va(where(node, &lst_a))))
		{
			min = count_instruct_a(node, lst_b, va(where(node, &lst_a)));
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

static void	put_in_b(t_list **lst_a, t_list **lst_b, int n)
{
	t_list	*node;
	int		i;

	i = 0;
	node = *lst_b;
	while (n != *node->content && ++i)
		node = node->next;
	if (i < ft_lstsize(*lst_b) / 2)
	{
		while (*(*lst_b)->content != n)
		{
			r(lst_b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while (*(*lst_b)->content != n)
		{
			rr(lst_b);
			ft_printf("rrb\n");
		}
	}
	push(lst_a, lst_b);
	ft_printf("pb\n");
}

void	sort(t_list **lst_a, t_list **lst_b)
{
	t_list	*node;

	while (ft_lstsize(*lst_a) > 3)
	{
		node = search_a(*lst_a, *lst_b);
		duble_r(node, lst_a, lst_b);
		while (*node->content != *(*lst_a)->content)
		{
			if (where(node, lst_a) < 0)
			{
				rr(lst_a);
				ft_printf("rra\n");
			}
			if (where(node, lst_a) > 0)
			{
				r(lst_a);
				ft_printf("ra\n");
			}
		}
		put_in_b(lst_a, lst_b, max_min(*lst_b, *(*lst_a)->content));
	}
	sort_last_3(lst_a);
	sort_b(lst_a, lst_b);
	ft_lstclear(lst_a, free);
	ft_lstclear(lst_b, free);
}
