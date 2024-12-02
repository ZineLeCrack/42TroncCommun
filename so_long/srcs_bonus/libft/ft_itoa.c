/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:21:20 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/22 09:53:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(long n, int len)
{
	long	coeff;

	coeff = 1;
	if (n == 0)
		len++;
	while (coeff <= n)
	{
		len++;
		coeff *= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	m;

	m = (long)n;
	len = 0;
	if (n < 0)
	{
		len++;
		m *= -1;
	}
	len = ft_itoalen(m, len);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = m % 10 + '0';
		m = m / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(-100);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
