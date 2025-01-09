/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:03:24 by rlebaill          #+#    #+#             */
/*   Updated: 2025/01/09 09:49:02 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command(char **split, char **envp, t_mini *mini)
{
	if (!split)
		return ;
	if (ft_strncmp(split[0], "echo", 4) == 0 && !split[0][4])
		ft_echo(split);
	else if (ft_strncmp(split[0], "export", 6) == 0 && !split[0][6])
		ft_export(split, mini);
	else if (ft_strncmp(split[0], "unset", 5) == 0 && !split[0][5])
		ft_unset(split, mini);
	else if (ft_strncmp(split[0], "cd", 2) == 0 && !split[0][2])
		ft_cd(split, mini->env);
	else if (ft_strncmp(split[0], "env", 3) == 0 && !split[0][3])
		ft_env(mini->env);
	else if (ft_strncmp(split[0], "./", 2) == 0)
		ft_exec(split[0], envp);
	else if (*split[0])
	{
		ft_shell(envp, split);
		wait(NULL);
	}
}

void	ft_ctrl_c(int sig)
{
	(void)sig;
	if (waitpid(-1, NULL, WNOHANG) == 0)
	{
		ft_printf("\n");
		return ;
	}
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static int	ft_open_quote(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
			if (!s[i])
				return (ft_printf("open quote\n"), 1);
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (!s[i])
				return (ft_printf("open quote\n"), 1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_mini	mini;
	char	*input;

	mini.env = ft_env_in_list(envp);
	mini.export = ft_env_sorted_in_list(&mini);
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	while (1 || ac || av[0])
	{
		input = readline("minishell> ");
		if (!input)
			return (ft_lstclear(&mini.env, free),
				ft_lstclear(&mini.export, free), ft_printf("exit\n"), 0);
		if (ft_strncmp(input, "exit", 4) == 0 && (!input[4] || input[4] == ' '))
			return (ft_lstclear(&mini.env, free), free(input),
				ft_lstclear(&mini.export, free), ft_printf("exit\n"), 0);
		if (*input && !ft_open_quote(input))
		{
			add_history(input);
			ft_execute(input, &mini, envp);
		}
		free(input);
	}
	return (0);
}
