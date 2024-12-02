/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:54:55 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/28 17:59:39 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_whatisit(char c, va_list thing)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(thing, int));
	else if (c == 's')
		count = ft_putstr(va_arg(thing, char *));
	else if (c == 'p')
		count = ft_puthexa(va_arg(thing, unsigned long long));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(thing, int));
	else if (c == 'u')
		count = ft_putnbr_unsigned(va_arg(thing, unsigned int));
	else if (c == 'x')
		count = ft_puthex(va_arg(thing, int), 0);
	else if (c == 'X')
		count = ft_puthex(va_arg(thing, int), 1);
	else
	{
		write(1, "%", 1);
		return (1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_whatisit(str[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	int		i;
	void *	str;

	str = "Hello World !";
	i = printf("%c %s %p %d %i %u %x %X %%\n",
	'a', (char *)str, str, -42, -42, 42, 42, 42);
	printf("--%d--\n", i);
	i = ft_printf("%c %s %p %d %i %u %x %X %%\n",
	'a', (char *)str, str, -42, -42, 42, 42, 42);
	ft_printf("--%d--\n", i);
	return (0);
}*/
