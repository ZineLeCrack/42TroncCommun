/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:36 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/21 14:26:46 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aff(t_list *lst_a, t_list *lst_b)
{
	ft_printf("A | B\n--|--\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			if (lst_a->content)
				ft_printf("%d | ", *lst_a->content);
			else
				ft_printf(". | ");
			lst_a = lst_a->next;
		}
		else
			ft_printf(". | ");
		if (lst_b)
		{
			if (lst_b->content)
				ft_printf("%d\n", *lst_b->content);
			else
				ft_printf(".\n");
			lst_b = lst_b->next;
		}
		else
			ft_printf(".\n");
	}
	ft_printf("-----\n");
}

static int	check_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		if (!argv[1][0] || check_dubble(argv[1]))
			return (write(2, "Error\n", 6), 1);
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' '
				&& argv[1][i] != '-')
				return (write(2, "Error\n", 6), 1);
			if (ft_atoi(&argv[1][i]) > INT_MAX
				|| ft_atoi(&argv[1][i]) < INT_MIN)
				return (write(2, "Error\n", 6), 1);
			i++;
		}
	}
	else if (argc > 2)
	{
		if (check_error_2(argc, argv))
			return (write(2, "Error\n", 6), 1);
	}
	return (0);
}

static t_list	*create_list(char *argv)
{
	int		i;
	int		*n;
	t_list	*noeud;
	t_list	*lst;

	argv = ft_strtrim(argv, " ");
	i = 0;
	lst = NULL;
	while (argv[i])
	{
		n = malloc(sizeof(int));
		if (!n)
			return (0);
		while (argv[i] == ' ' && argv[i])
			i++;
		*n = ft_atoi(&argv[i]);
		while (argv[i] && (ft_isdigit(argv[i]) || argv[i] == '-'))
			i++;
		noeud = ft_lstnew(n);
		ft_lstadd_back(&lst, noeud);
	}
	return (free(argv), lst);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;

	if (argc == 1)
		return (0);
	if (check_error(argc, argv))
		return (0);
	else if (argc == 2)
		lst_a = create_list(argv[1]);
	else
	{
		str = super_join(argv);
		lst_a = create_list(str);
		free(str);
	}
	lst_b = NULL;
	little_sort(&lst_a, &lst_b);
	if (is_sort(lst_a, lst_b, 1))
		return (ft_lstclear(&lst_a, free), 0);
	if (ft_lstsize(lst_a) == 2)
		return (swap(lst_a), ft_printf("sa\n"), 0);
	duble_push(&lst_a, &lst_b);
	sort(&lst_a, &lst_b);
	return (0);
}

/*
sa  : swap(lst_a);
sb  : swap(lst_b);
ss	: swap(lst_a) + swap(lst_b);
pa  : push(&lst_a, &lst_b);
pb  : push(&lst_b, &lst_a);
ra  : r(&lst_a);
rb  : r(&lst_b);
rr  : r(&lst_a) + r(&lst_b);
rra : rr(&lst_a);
rrb : rr(&lst_b);
rrr : rr(&lst_a) + rr(&lst_b);
*/
