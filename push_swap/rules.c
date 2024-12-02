/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:26:27 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/19 13:11:40 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = ft_lstlast(*lst);
	*lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	second_last = *lst;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	swap(t_list *lst)
{
	int	*tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}

void	push(t_list **lst_a, t_list **lst_b)
{
	t_list	*noeud;

	if (!lst_a || !*lst_a)
		return ;
	noeud = *lst_a;
	*lst_a = (*lst_a)->next;
	noeud->next = *lst_b;
	*lst_b = noeud;
}
