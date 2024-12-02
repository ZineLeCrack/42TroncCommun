/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:17:16 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/23 10:10:18 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (s[i] == c)
		return ((char *)&s[i]);
	else if (j >= 0)
		return ((char *)&s[j]);
	else
		return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		printf("%s\n", ft_strrchr(argv[1], (int)argv[2][0]));
		printf("%s\n", strrchr(argv[1], (int)argv[2][0]));
	}
	return (0);
}*/
