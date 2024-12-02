/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:29:43 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/17 18:01:32 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strlen

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	if (!ft_strlen(little))
		return ((char *)big);
	if (!ft_strlen(big))
		return (NULL);
	if ((int)len < 0)
		len = ft_strlen(big);
	i = 0;
	while ((size_t)i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < (int)len)
		{
			if (j == (int)ft_strlen(little) - 1)
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	//printf("%s\n", strnstr(argv[1], argv[2], (size_t)0));
	printf("%s\n", ft_strnstr("Hello", "e", -1));
	return (0);
}*/
