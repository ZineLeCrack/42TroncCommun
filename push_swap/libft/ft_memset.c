/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/21 15:36:17 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*m;
	size_t	i;

	m = (char *)s;
	i = 0;
	while (i < n)
	{
		m[i] = (char)c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>

int	main(void)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc(5);
	if (!a)
		return (0);
	a = ft_memset((void *)a, 'a', 5);
	while (i < 5)
	{
		printf("%c\n", a[i]);
		i++;
	}
	return (0);
}*/
