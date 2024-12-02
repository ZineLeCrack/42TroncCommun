/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:51:38 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/23 10:26:49 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_lstnew

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void	ft_del(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	*elem;
	char	*str;
	
	str = malloc(sizeof(char) * 11);
	elem = ft_lstnew((void *)str);
	printf("%d\n", ft_lstsize(elem));
    ft_lstdelone(elem, ft_del);
	printf("%d\n", ft_lstsize(elem));
    return (0);
}*/
