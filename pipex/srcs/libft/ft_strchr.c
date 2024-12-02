/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:48:34 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/23 10:08:59 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("%s\n", ft_strchr(argv[1], (int)argv[2][0]));
		printf("%s\n", strchr(argv[1], (int)argv[2][0]));
	}
	return (0);
}*/
