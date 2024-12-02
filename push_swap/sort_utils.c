/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:11:22 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 13:16:17 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_last_3_2(t_list **lst, int a, int b, int c)
{
	if (a < b && b > c)
	{
		rr(lst);
		ft_printf("rra\n");
		if (a < c)
		{
			swap(*lst);
			ft_printf("sa\n");
		}
	}
	else if (a < b && b < c && a < c)
	{
		r(lst);
		ft_printf("ra\n");
		r(lst);
		ft_printf("ra\n");
	}
	else if (a > b && b > c)
	{
		swap(*lst);
		ft_printf("sa\n");
		rr(lst);
		ft_printf("rra\n");
	}
}

void	sort_last_3(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize(*lst) == 3)
	{
		a = *(*lst)->content;
		b = *(*lst)->next->content;
		c = *(*lst)->next->next->content;
		if (a > b && b < c)
		{
			if (a < c)
			{
				swap(*lst);
				ft_printf("sa\n");
			}
			else
			{
				r(lst);
				ft_printf("ra\n");
			}
		}
		else
			sort_last_3_2(lst, a, b, c);
	}
}

int	min_max(t_list **lst, int n)
{
	t_list	*node;
	int		min;

	node = *lst;
	min = *node->content;
	while (node)
	{
		if (min < *node->content)
			min = *node->content;
		node = node->next;
	}
	node = *lst;
	if (min < n)
		return (get_min(*lst, min));
	while (node)
	{
		if (*node->content > n && *node->content < min)
			min = *node->content;
		node = node->next;
	}
	return (min);
}

static void	put_in_a(t_list **lst_a, t_list **lst_b, int n)
{
	t_list	*node;
	int		i;

	i = 0;
	node = *lst_a;
	while (n != *node->content && ++i)
		node = node->next;
	if (i < ft_lstsize(*lst_a) / 2)
	{
		while (*(*lst_a)->content != n)
		{
			r(lst_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (*(*lst_a)->content != n)
		{
			rr(lst_a);
			ft_printf("rra\n");
		}
	}
	push(lst_b, lst_a);
	ft_printf("pa\n");
}

void	sort_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*node;

	while (ft_lstsize(*lst_b) > 1)
	{
		node = search_b(*lst_a, *lst_b);
		if (*node->content == *(*lst_a)->next->content)
		{
			swap(*lst_b);
			ft_printf("sb\n");
		}
		else if (*node->content == *(ft_lstlast(*lst_a)->content))
		{
			rr(lst_b);
			ft_printf("rrb\n");
		}
		put_in_a(lst_a, lst_b, min_max(lst_a, *(*lst_b)->content));
	}
	put_in_a(lst_a, lst_b, min_max(lst_a, *(*lst_b)->content));
	finish(lst_a);
}
