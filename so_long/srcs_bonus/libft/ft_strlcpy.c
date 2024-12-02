/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:47:33 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:57:37 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	const char src[] = "Hello";
	char dest[] = "World";
	size_t size = 3;
	//const char src1[] = "Hello";
	//char dest1[] = "World";

	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	//printf("%zu\n", strlcpy(dest1, src1, size));
	//printf("%s\n", dest1);
	return (0);
}*/
