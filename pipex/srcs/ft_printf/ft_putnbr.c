/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:41:15 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/12 13:01:34 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_itoalen(long n, int len)
{
	long	coeff;

	if (n < 0)
	{
		len++;
		n *= -1;
	}
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

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	tmp;

// 	if (n < -2100000000)
// 	{
// 		write(fd, "-2", 2);
// 		ft_putnbr_fd(-(n + 2000000000), fd);
// 	}
// 	else if (n < 0)
// 	{
// 		write(fd, "-", 1);
// 		ft_putnbr_fd(-n, fd);
// 	}
// 	else if (0 <= n && n <= 9)
// 	{
// 		tmp = n + '0';
// 		write(fd, &tmp, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 		ft_putnbr_fd(n % 10, fd);
// 	}
// }

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	len = ft_itoalen(n, len);
	ft_putnbr_fd(n, 1);
	return (len);
}
