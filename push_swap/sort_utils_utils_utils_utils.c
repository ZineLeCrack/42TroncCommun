/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils_utils_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:16:04 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 10:58:55 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*super_join(char **argv)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 2;
	str = ft_strdup(argv[1]);
	while (argv[i])
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = tmp;
		i++;
	}
	return (str);
}

int	get_min(t_list *lst, int n)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		if (n > *node->content)
			n = *node->content;
		node = node->next;
	}
	return (n);
}

int	get_max(t_list *lst, int n)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		if (n < *node->content)
			n = *node->content;
		node = node->next;
	}
	return (n);
}

int	where(t_list *node, t_list **lst)
{
	t_list	*where;
	int		i;

	i = 0;
	where = *lst;
	while (*node->content != *where->content)
	{
		i++;
		where = where->next;
	}
	if (i > ft_lstsize(*lst) / 2)
		i = i - ft_lstsize(*lst);
	return (i);
}

int	va(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}
