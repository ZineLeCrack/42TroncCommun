/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:01 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:23:08 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("%c\n", tolower(argv[1][0]));
		printf("%c\n", ft_tolower(argv[1][0]));
	}
	return (0);
}*/
