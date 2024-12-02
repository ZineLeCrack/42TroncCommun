/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:36:26 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 17:02:38 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;
	unsigned int	j;

	destlen = 0;
	srclen = 0;
	while (dest[destlen])
		destlen++;
	while (src[srclen])
		srclen++;
	i = 0;
	j = destlen;
	if (size <= destlen)
		return (srclen + size);
	while (src[i] && i < size - destlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (destlen + srclen);
}

/*#include <stdio.h>

int	main(void)
{
	char	dest[] = "Hello ";
	char	src[] = "World";

	printf("%zu\n", ft_strlcat(dest, src, 10));
	printf("%s\n", dest);
	return (0);
}*/
