/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:38:21 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/18 13:45:59 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;

	if (!dest && !src)
		return (NULL);
	i = n - 1;
	if ((const char *)src < (char *)dest)
	{
		while (i >= 0)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdefghij";
	char str2[] = "abcdefghij";
	ft_memmove(str1 + 2, str1 + 3, 3);
	printf("%s\n", str1);
	memmove(str2 + 2, str2 + 3, 3);
	printf("%s\n", str2);
	return 0;
}*/
