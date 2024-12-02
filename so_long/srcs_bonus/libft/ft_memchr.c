/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:00:53 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 17:02:45 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < (int)n)
	{
		if (str[i] == (char)c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";
	printf("%s\n", 	(char *)ft_memchr(str1, 'd', 4));
	printf("%s\n", (char *)memchr(str2, 'd', 4));
	return 0;
}*/
