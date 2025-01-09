/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:07:09 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/08 18:18:10 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_have_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(char **split, t_mini *mini)
{
	t_list	*lst;
	int		i;

	lst = mini->export;
	if (ft_get_size_mat(split) == 1)
	{
		while (lst)
		{
			ft_printf("%s\n", lst->content);
			lst = lst->next;
		}
	}
	else
	{
		i = 1;
		while (split[i])
		{
			if (ft_have_equal(split[i]))
			{
				lst = ft_lstnew(ft_strdup(split[i]));
				ft_lstadd_back(&mini->env, lst);
			}
			i++;
		}
	}
}

static void	ft_remove_node(t_list **env, t_list *lst)
{
	t_list	*i;

	i = *env;
	while (i->next != lst)
		i = i ->next;
	i->next = i->next->next;
	ft_lstdelone(lst, free);
}

void	ft_unset(char **split, t_mini *mini)
{
	int		i;
	t_list	*lst;

	if (ft_get_size_mat(split) == 1)
		return ;
	i = 1;
	lst = mini->env;
	while (split[i])
	{
		while (lst)
		{
			if (ft_strncmp(split[i], lst->content, ft_strlen(split[i])) == 0
				&& lst->content[ft_strlen(split[i])] == '=')
			{
				ft_remove_node(&mini->env, lst);
				return ;
			}
			lst = lst->next;
		}
		i++;
	}
}
