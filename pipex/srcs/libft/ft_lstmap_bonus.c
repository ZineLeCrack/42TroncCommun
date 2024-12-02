/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:16:53 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/25 09:57:32 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		elem = ft_lstnew(NULL);
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		elem->content = f(lst->content);
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}

/*void	ft_del(void *content)
{
	free(content);
}

void *ft(void *content)
{
    int *new_value;
	
	new_value = malloc(sizeof(int));
	if (!new_value)
        return (NULL);
    *new_value = *(int *)content + 1;
    return (new_value);
}

#include <stdio.h>

int main(void)
{
    t_list	*list = NULL;
	t_list	*new_list;
	
    int *value;
    for (int i = 0; i < 5; i++)
    {
        value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }
    printf("Debut : %d\n", ft_lstsize(list));
    new_list = ft_lstmap(list, ft, ft_del);
    printf("Apres : %d\n", ft_lstsize(new_list));
    ft_lstclear(&list, ft_del);
    ft_lstclear(&new_list, ft_del);
    return 0;
}*/
