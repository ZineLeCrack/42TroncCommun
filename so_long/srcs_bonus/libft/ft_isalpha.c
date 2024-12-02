/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:40:00 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:57 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
		if (argc > 0)
			printf("%d\n", ft_isalpha(argv[1][0]));
		return(0);
}*/
