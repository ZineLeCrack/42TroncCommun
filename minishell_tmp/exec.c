/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:22:04 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/09 15:05:05 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_commands(char **split)
{
	int	i;

	i = 0;
	if (ft_strncmp(split[0], "|", 1) == 0 && !split[0][1])
		return (1);
	while (split[i] && !(ft_strncmp(split[i], "|", 1) == 0 && !split[i][1]))
		i++;
	return (i);
}

static char	**ft_extracte_command(char **split, int n)
{
	char	**command;
	int		i;

	i = 0;
	command = malloc(sizeof(char *) * (n + 1));
	while (i < n)
	{
		command[i] = ft_strdup(split[i]);
		i++;
	}
	command[i] = NULL;
	return (command);
}

static char	***ft_split_split(char **split)
{
	char	***splited_split;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	j = 0;
	while (split[++i])
		if (ft_strncmp(split[i], "|", 1) == 0 && !split[i][1])
			count++;
	count = count * 2 + 1;
	splited_split = malloc(sizeof(char **) * (count + 2));
	i = 0;
	while (split[i])
	{
		count = ft_count_commands(&split[i]);
		splited_split[j++] = ft_extracte_command(&split[i], count);
		i += count;
	}
	splited_split[j] = NULL;
	splited_split[j + 1] = NULL;
	return (splited_split);
}

static int	ft_pipe(char ***splited_split, char **split,
	char **envp, t_mini *mini)
{
	int		fd[2];
	int		i;
	int		prev_fd;
	pid_t	pid;

	prev_fd = 0;
	i = 0;
	while (splited_split[i])
	{
		if (splited_split[i + 1] && pipe(fd) == -1)
			return (ft_free_split(split), 1);
		pid = fork();
		if (pid == -1)
			return (ft_free_split(split), 1);
		if (pid == 0)
		{
			if (splited_split[i + 1])
				dup2(fd[1], STDOUT_FILENO);
			if (prev_fd != 0)
				dup2(prev_fd, STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			ft_command(splited_split[i], envp, mini);
			exit (0);
		}
		if (prev_fd != 0)
			close(prev_fd);
		if (splited_split[i + 1])
			prev_fd = fd[0];
		close(fd[1]);
		i += 2;
	}
	return (1);
}

int	ft_execute(char *input, t_mini *mini, char **envp)
{
	char	***splited_split;
	char	**split;
	int		i;

	i = 0;
	split = ft_split_quote(input);
	splited_split = ft_split_split(split);
	if (!splited_split)
		return (1);
	if (splited_split[1])
		ft_pipe(splited_split, split, envp, mini);
	else
		ft_command(splited_split[0], envp, mini);
	while (wait(NULL) > 0)
		;
	ft_free_splited_split(splited_split);
	ft_free_split(split);
	return (1);
}
