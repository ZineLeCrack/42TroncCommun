/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:16:29 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/09 15:01:08 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_mini
{
	t_list	*env;
	t_list	*export;
}	t_mini;

void	ft_command(char **split, char **envp, t_mini *mini);
int		ft_execute(char *input, t_mini *mini, char **envp);
int		ft_get_size_mat(char **env);
t_list	*ft_env_in_list(char **envp);
t_list	*ft_env_sorted_in_list(t_mini *mini);
void	ft_unset(char **split, t_mini *mini);
void	ft_export(char **split, t_mini *mini);
void	ft_shell(char **envp, char **args);
void	ft_env(t_list *env);
void	ft_ctrl_c(int sig);
void	ft_exec(char *input, char **envp);
void	ft_cd(char **split, t_list *env);
void	ft_echo(char **split);
char	**ft_split_quote(char *input);
void	ft_free_split(char **split);
void	ft_free_splited_split(char ***splited_split);

#endif