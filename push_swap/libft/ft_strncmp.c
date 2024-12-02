/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:08:08 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/18 10:12:19 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		c;
	size_t	i;

	c = 0;
	i = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0' && i < n)
	{
		c++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}

/*#include <stdio.h>

int	main(void)
{
	char	s1[] = "Hella World";
	char	s2[] = "Hello";

	printf("%d\n", ft_strncmp(s1, s2, 5));
	return (0);
}*/
