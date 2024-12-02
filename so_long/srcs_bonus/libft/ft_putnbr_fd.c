/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:38:39 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:24:53 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;

	if (n < -2100000000)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(-(n + 2000000000), fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (0 <= n && n <= 9)
	{
		tmp = n + '0';
		write(fd, &tmp, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/*int main(void)
{
	ft_putnbr_fd(-2147483647, 1);
	return (0);
}*/
