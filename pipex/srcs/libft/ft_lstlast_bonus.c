/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:22:06 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 10:32:26 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew ft_lstadd_front

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem);
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*e1;
	t_list	*e2;
	t_list	*e3;
	t_list	*e4;

	e1 = ft_lstnew((void *)"1");
	e2 = ft_lstnew((void *)"2");
	e3 = ft_lstnew((void *)"3");
	e4 = ft_lstnew((void *)"4");

	ft_lstadd_front(&e4, e3);
	ft_lstadd_front(&e3, e2);
	ft_lstadd_front(&e2, e1);

	printf("%c\n", ((char *)(ft_lstlast(e1)->content))[0]);
	return (0);
}*/
