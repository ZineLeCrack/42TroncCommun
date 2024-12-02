/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:41:45 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/19 14:17:53 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_instruct_b(t_list *node, t_list *lst_a, int m)
{
	t_list	*node_a;
	int		i;
	int		n;
	int		max;

	i = 0;
	n = *node->content;
	max = min_max(&lst_a, n);
	node_a = lst_a;
	while (max != *node_a->content)
	{
		i++;
		node_a = node_a->next;
	}
	if (i > ft_lstsize(lst_a) - i)
		i = ft_lstsize(lst_a) - i;
	return (i + m);
}

t_list	*search_b(t_list *lst_a, t_list *lst_b)
{
	int		first;
	int		second;
	int		last;

	first = count_instruct_b(lst_b, lst_a, 1);
	second = count_instruct_b(lst_b->next, lst_a, 2);
	last = count_instruct_b(ft_lstlast(lst_b), lst_a, 2);
	if (first <= second && first <= last)
		return (lst_b);
	if (second <= last)
		return (lst_b->next);
	return (ft_lstlast(lst_b));
}

void	finish(t_list **lst)
{
	t_list	*node;
	int		min;
	int		i;

	i = 0;
	node = *lst;
	min = *(*lst)->content;
	while (node)
	{
		if (min > *node->content)
			min = *node->content;
		node = node->next;
	}
	node = *lst;
	while (min != *node->content)
	{
		i++;
		node = node->next;
	}
	if (i < ft_lstsize(*lst) / 2)
		ft_ra(lst, min);
	else
		ft_rra(lst, min);
}

void	finish_b(t_list **lst)
{
	t_list	*node;
	int		max;
	int		i;

	i = 0;
	node = *lst;
	max = *(*lst)->content;
	while (node)
	{
		if (max < *node->content)
			max = *node->content;
		node = node->next;
	}
	node = *lst;
	while (max != *node->content)
	{
		i++;
		node = node->next;
	}
	if (i < ft_lstsize(*lst) / 2)
		ft_ra(lst, max);
	else
		ft_rra(lst, max);
}
