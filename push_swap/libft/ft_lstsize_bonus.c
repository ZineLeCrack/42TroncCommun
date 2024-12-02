/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:26 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 10:33:05 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew ft_lstadd_front

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*elem;

	if (!lst)
		return (0);
	i = 0;
	elem = lst;
	while (elem != NULL)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*e1;
	t_list	*e2;
	t_list	*e3;
	t_list	*e4;

	e1 = ft_lstnew((void *)1);
	e2 = ft_lstnew((void *)2);
	e3 = ft_lstnew((void *)3);
	e4 = ft_lstnew((void *)4);

	ft_lstadd_front(&e4, e3);
	ft_lstadd_front(&e3, e2);
	ft_lstadd_front(&e2, e1);

	printf("%d\n", ft_lstsize(e1));
	return (0);
}*/
