/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:58 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 18:40:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new_elem1;
	t_list	*new_elem2;
	char	*content1 = "2";
	char	*content2 = "1";
	
	new_elem1 = ft_lstnew(content1);
	head = new_elem1;
	printf("Premier élément: %s\n", (char *)head->content);
	new_elem2 = ft_lstnew(content2);
	ft_lstadd_front(&head, new_elem2);
	printf("\nPremier élément: %s\n", (char *)head->content);
	printf("Deuxième élément: %s\n", (char *)head->next->content);
}*/
