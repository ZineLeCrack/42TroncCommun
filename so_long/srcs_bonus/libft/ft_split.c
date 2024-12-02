/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:30:05 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/21 11:26:48 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strlen

static int	ft_count_words(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (s[i] != c && s[i])
	{
		n++;
	}
	i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static char	*next_word(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	len = i;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

void	ft_freeall(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mat = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!mat)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			mat[j] = next_word(&s[i], c);
			if (!mat[j])
				return (ft_freeall(mat), NULL);
			j++;
			i += ft_strlen(mat[j - 1]);
		}
	}
	mat[j] = NULL;
	return (mat);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	**mat;
// 	int		i;

// 	i = 0;
// 	if (argc > 2)
// 	{
// 		mat = ft_split(argv[1], argv[2][0]);
// 		printf("%d\n", ft_count_words(argv[1], argv[2][0]));
// 		while (mat[i])
// 		{
// 			printf("%s\n", mat[i]);
// 			free(mat[i]);
// 			i++;
// 		}
// 		free(mat);
// 	}
// 	return (0);
// }
