/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:54:36 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 13:12:32 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*elem;

	elem = lst;
	while (elem)
	{
		f(elem->content);
		elem = elem->next;
	}
}

/*#include <stdio.h>

void	ft_test(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*e1;
	t_list	*e2;
	t_list	*e3;

	e1 = ft_lstnew("42");
	e2 = ft_lstnew("Hello");
	e3 = ft_lstnew("World");

	ft_lstadd_back(&e1, e2);
	ft_lstadd_back(&e1, e3);
	ft_lstiter(e1, ft_test);
	return (0);
}*/