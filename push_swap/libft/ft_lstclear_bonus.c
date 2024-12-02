/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:19:44 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/18 09:58:54 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew ft_lstsize ft_lstdelone ft_lstadd_back

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	elem = *lst;
	while (elem)
	{
		next = elem->next;
		ft_lstdelone(elem, del);
		elem = next;
	}
	*lst = NULL;
}

/*void	ft_del(void *content)
{
	free(content);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list	*e1;
	t_list	*e2;
	t_list	*e3;
	t_list	*e4;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = malloc(sizeof(char) * 6);
	strcpy(str1, "1");
	str2 = malloc(sizeof(char) * 6);
	strcpy(str2, "2");
	str3 = malloc(sizeof(char) * 6);
	strcpy(str3, "3");
	str4 = malloc(sizeof(char) * 6);
	strcpy(str4, "4");

	e1 = ft_lstnew((void *)str1);
	e2 = ft_lstnew((void *)str2);
	e3 = ft_lstnew((void *)str3);
	e4 = ft_lstnew((void *)str4);

	ft_lstadd_back(&e1, e2);
	ft_lstadd_back(&e1, e3);
	ft_lstadd_back(&e1, e4);

	printf("Avant : %d\n", ft_lstsize(e1));
	ft_lstclear(&e2, ft_del);
	e1->next = NULL;
	printf("Apres : %d\n", ft_lstsize(e1));
	ft_lstclear(&e1, ft_del);

	return (0);
}*/
