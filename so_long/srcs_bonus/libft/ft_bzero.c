/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:26:17 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main(void)
{
	int	*a;
	int	i;

	i = 0;
	a = malloc(5);
	if (!a)
		return (0);
	a = ft_bzero((void *)a, 5);
	while (i < 5)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}*/
