/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:52:53 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 15:02:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_2(t_list **lst, int a, int b, int c)
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
	else if (a > b && b > c)
	{
		swap(*lst);
		ft_printf("sa\n");
		rr(lst);
		ft_printf("rra\n");
	}
}

static void	sort_3(t_list **lst)
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
			sort_3_2(lst, a, b, c);
	}
}

static void	sort_4(t_list **lst_a, t_list **lst_b)
{
	int		min;
	t_list	*node;

	node = *lst_a;
	min = *node->content;
	while (node)
	{
		if (min > *node->content)
			min = *node->content;
		node = node->next;
	}
	while (*(*lst_a)->content != min)
	{
		r(lst_a);
		ft_printf("ra\n");
	}
	push(lst_a, lst_b);
	ft_printf("pb\n");
	sort_3(lst_a);
	push(lst_b, lst_a);
	ft_printf("pa\n");
}

void	little_sort(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 2 && lst_b)
	{
		if (*(*lst_a)->content > *(*lst_a)->next->content)
		{
			swap(*lst_a);
			ft_printf("sa\n");
		}
	}
	if (ft_lstsize(*lst_a) == 3)
		sort_3(lst_a);
	if (ft_lstsize(*lst_a) == 4 && !is_sort(*lst_a, NULL, 1))
		sort_4(lst_a, lst_b);
}
