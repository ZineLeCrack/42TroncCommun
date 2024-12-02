/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:41:03 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 15:14:09 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (!*lst)
		*lst = new;
	else
	{
		elem = *lst;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = new;
	}
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new_elem1;
	t_list	*new_elem2;
	char	*content1 = "1";
	char	*content2 = "2";
	
	new_elem1 = ft_lstnew(content1);
	head = new_elem1;
	printf("Premier élément: %s\n", (char *)head->content);
	new_elem2 = ft_lstnew(content2);
	ft_lstadd_back(&head, new_elem2);
	printf("\nPremier élément: %s\n", (char *)head->content);
	printf("Deuxième élément: %s\n", (char *)head->next->content);
}*/
