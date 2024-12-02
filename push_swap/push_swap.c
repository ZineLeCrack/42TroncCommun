/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:26:14 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/20 14:29:59 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dubble_2(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error_2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (check_dubble_2(argv))
		return (1);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			return (1);
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dubble(char *argv)
{
	char	**split;
	int		err;
	int		j;
	int		i;

	err = 0;
	i = 0;
	split = ft_split(argv, ' ');
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
				err = 1;
			j++;
		}
		free(split[i]);
		i++;
	}
	free(split);
	return (err);
}

int	is_sort(t_list *lst_a, t_list *lst_b, int n)
{
	if (lst_b)
		return (0);
	if (n)
	{
		while (lst_a->next)
		{
			if (*lst_a->content > *lst_a->next->content)
				return (0);
			lst_a = lst_a->next;
		}
	}
	else
	{
		while (lst_a->next)
		{
			if (*lst_a->content < *lst_a->next->content)
				return (0);
			lst_a = lst_a->next;
		}
	}
	return (1);
}

void	duble_push(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_printf("pb\n");
	push(lst_a, lst_b);
	ft_printf("pb\n");
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
