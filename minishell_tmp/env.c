/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:33:33 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/08 13:21:26 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_env_in_list(char **envp)
{
	int		i;
	t_list	*env;

	env = ft_lstnew(ft_strdup(envp[0]));
	i = 1;
	while (envp[i])
	{
		ft_lstadd_back(&env, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
	return (env);
}

void	ft_env(t_list *env)
{
	t_list	*lst;

	lst = env;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}

static char	**ft_create_env_sorted(t_list *env)
{
	int		i;
	t_list	*lst;
	char	**env_sorted;

	i = 0;
	lst = env;
	env_sorted = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	while (lst)
	{
		env_sorted[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	env_sorted[i] = NULL;
	return (env_sorted);
}

static void	ft_sort(char **env)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], ft_strlen(env[i])) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
}

t_list	*ft_env_sorted_in_list(t_mini *mini)
{
	char	**env_sorted;
	t_list	*export;

	env_sorted = ft_create_env_sorted(mini->env);
	ft_sort(env_sorted);
	export = ft_env_in_list(env_sorted);
	ft_free_split(env_sorted);
	return (export);
}
