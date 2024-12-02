/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:38:51 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/28 14:15:47 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

static void	close_all(int files[2], int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
}

static void	write_in_pipe(int files[2], int fd[2], char **argv, char **envp)
{
	char	**cmd1;
	char	*path;

	dup2(files[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	cmd1 = ft_split(argv[2], ' ');
	path = ft_strjoin("/bin/", cmd1[0]);
	execve(path, cmd1, envp);
	write(2, "Execve failed for cmd1\n", 23);
	free_cmd(cmd1);
	free(path);
	exit(1);
}

static void	write_in_file(int files[2], int fd[2], char **argv, char **envp)
{
	char	**cmd2;
	char	*path;

	dup2(fd[0], STDIN_FILENO);
	dup2(files[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(files[0]);
	close(files[1]);
	cmd2 = ft_split(argv[3], ' ');
	path = ft_strjoin("/bin/", cmd2[0]);
	execve(path, cmd2, envp);
	write(2, "Execve failed for cmd2\n", 23);
	free_cmd(cmd2);
	free(path);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		files[2];
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40), 1);
	if (pipe(fd) == -1)
		return (write(2, "pipe error\n", 11), 1);
	pid = fork();
	if (pid == -1)
		return (write(2, "fork error\n", 11), 1);
	files[0] = open(argv[1], O_RDONLY);
	if (files[0] == -1)
		return (write(1, "failed open file\n", 17), 1);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (files[1] == -1)
		return (write(1, "failed open file\n", 17), 1);
	if (pid == 0)
		write_in_pipe(files, fd, argv, envp);
	if (fork() == 0)
		write_in_file(files, fd, argv, envp);
	close_all(files, fd);
	wait(NULL);
	wait(NULL);
	return (0);
}
