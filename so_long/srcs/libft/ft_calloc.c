/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:31:05 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/22 09:51:46 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*aloc;

	total = nmemb * size;
	aloc = malloc(total);
	if (!aloc)
		return (NULL);
	ft_memset(aloc, 0, total);
	return (aloc);
}

/*#include <stdio.h>

int	main(void)
{
	int	*a;
	int	i;

	i = 0;
	a = ft_calloc(1, 3);
	while (i < 3)
	{
		printf("%d\n", a[i]);
		i++;
	}
	free(a);
	return (0);
}*/
