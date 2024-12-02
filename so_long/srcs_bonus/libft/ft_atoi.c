/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:34:01 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/21 09:06:03 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		resultat;
	int		signe;
	int		i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		signe *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (signe * resultat);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d\n", atoi(argv[1]));
	}
	return (0);
}*/
