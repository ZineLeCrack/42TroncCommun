/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:26:34 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/09 15:14:38 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **split, t_list *env)
{
	if (!split || !env)
		return ;
	if (!split[1])
	{
		if (chdir(getenv("HOME")) != 0)
			perror("Error: HOME does not exist in the environment\n");
		return ;
	}
	if (chdir(split[1]) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(split[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void	ft_echo(char **split)
{
	int	i;

	i = 1;
	if (!split[i])
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	if (ft_strncmp(split[1], "-n", 2) == 0 && !split[1][2])
	{
		i++;
		if (!split[i])
			return ;
	}
	ft_putstr_fd(split[i], 1);
	i++;
	while (split[i])
	{
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(split[i], 1);
		i++;
	}
	if (!(ft_strncmp(split[1], "-n", 2) == 0 && !split[1][2]))
		ft_putchar_fd('\n', 1);
}

void	ft_shell(char **envp, char **args)
{
	pid_t	pid;
	char	*cmd_path;
	int		i;

	i = 0;
	if (!args)
		return ;
	cmd_path = ft_strjoin("/usr/bin/", args[0]);
	if (!cmd_path)
		perror("Error: malloc error\n");
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			ft_printf("%s: command not found\n", args[0]);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	free(cmd_path);
}

void	ft_exec(char *input, char **envp)
{
	char	**split;
	pid_t	pid;

	split = ft_split_quote(input);
	if (!split[0][2])
	{
		ft_printf("permission denied: ./\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork error\n");
		return ;
	}
	if (pid == 0)
	{
		if (execve(&split[0][2], split, envp) == -1)
		{
			ft_printf("file not found : %s\n", &split[0][2]);
			exit (0);
		}
	}
	wait(NULL);
}
