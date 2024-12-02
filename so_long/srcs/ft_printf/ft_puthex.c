/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:38:52 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/28 16:42:15 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, int a)
{
	char	*base;
	char	buffer[8];
	int		count;
	int		i;

	count = 0;
	if (!a)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (num > 0)
	{
		buffer[i++] = base[num % 16];
		num /= 16;
	}
	count = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (count);
}

/*#include <stdio.h>

int main(void)
{
	printf("\n%d\n%d\n", ft_puthex(45455, 0), ft_puthex(45455, 1));
	return (0);
}*/
