/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:17:24 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/19 17:02:40 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotaterotate(int i1, int i2, t_list **lst_a, t_list **lst_b)
{
	while (i1 < 0 && i2 < 0)
	{
		i1++;
		i2++;
		rr(lst_a);
		rr(lst_b);
		ft_printf("rrr\n");
	}
	while (i1 > 0 && i2 > 0)
	{
		i1--;
		i2--;
		r(lst_a);
		r(lst_b);
		ft_printf("rr\n");
	}
}

void	duble_r(t_list *node, t_list **lst_a, t_list **lst_b)
{
	int		n;
	int		i1;
	int		i2;
	t_list	*noeud;

	i1 = 0;
	i2 = 0;
	n = max_min(*lst_b, *node->content);
	noeud = *lst_b;
	while (n != *noeud->content)
	{
		i1++;
		noeud = noeud->next;
	}
	noeud = *lst_a;
	while (*node->content != *noeud->content)
	{
		i2++;
		noeud = noeud->next;
	}
	if (i1 > ft_lstsize(*lst_b) / 2)
		i1 = i1 - ft_lstsize(*lst_b);
	if (i2 > ft_lstsize(*lst_a) / 2)
		i2 = i2 - ft_lstsize(*lst_a);
	rotaterotate(i1, i2, lst_a, lst_b);
}

t_list	*ft_lstsecondlast(t_list *lst)
{
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem->next->next != NULL)
		elem = elem->next;
	return (elem);
}

void	ft_ra(t_list **lst, int min)
{
	while (*(*lst)->content != min)
	{
		r(lst);
		ft_printf("ra\n");
	}
}

void	ft_rra(t_list **lst, int min)
{
	while (*(*lst)->content != min)
	{
		rr(lst);
		ft_printf("rra\n");
	}
}
