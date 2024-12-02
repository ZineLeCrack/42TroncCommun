/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/18 13:30:27 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*strdest;
	char	*strsrc;

	if (!dest && !src)
		return (NULL);
	i = 0;
	strsrc = (char *)src;
	strdest = (char *)dest;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	src[3];
	//char	dest[3];

	//src[0] = 'a';
	//src[1] = 'b';
	//src[2] = 'c';
	//dest[0] = 'x';
	//dest[1] = 'y';
	//dest[2] = 'z';
	printf("%s\n", (char*)ft_memcpy((void*)0, (void*)0, (size_t)2));
	printf("%s\n", (char*)memcpy((void*)0, (void*)0, (size_t)2));
	return (0);
}*/
