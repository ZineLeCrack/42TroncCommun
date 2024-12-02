/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:35:33 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/25 10:03:53 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strlen ft_strdup ft_strlcpy

static int	is_in(char c, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		stop;
	char	*str;

	len = ft_strlen(s1);
	i = 0;
	while (is_in(s1[i], set))
		i++;
	if (i == len)
		return (ft_strdup(""));
	stop = len;
	while (is_in(s1[stop - 1], set))
		stop--;
	str = malloc(sizeof(char) * (stop - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], stop - i + 1);
	str[stop - i] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	char *str;

	if (argc > 2)
	{
		str = ft_strtrim(argv[1], argv[2]);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}*/
