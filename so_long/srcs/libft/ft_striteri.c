/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:03:42 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:24:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

void	test(unsigned int n, char *c)
{
	if (n >= 0)
		*c = *c + 1;
}

int	main(void)
{
	char	str[5] = "Hello";

	ft_striteri(str, test);
	printf("%s\n", str);
	return (0);
}*/
