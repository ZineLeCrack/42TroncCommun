/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:24:28 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/28 17:59:27 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa_recursive(unsigned long long num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
		count = ft_puthexa_recursive(num / 16, base);
	count++;
	write(1, &base[num % 16], 1);
	return (count);
}

int	ft_puthexa(unsigned long long num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += ft_puthexa_recursive(num, base);
	return (count);
}
