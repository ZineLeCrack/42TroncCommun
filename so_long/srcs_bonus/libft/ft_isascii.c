/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:10 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 0)
		printf("%d\n", ft_isascii(argv[1][0]));
	return(0);
}*/
