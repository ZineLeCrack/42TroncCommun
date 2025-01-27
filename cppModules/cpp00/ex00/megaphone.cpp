/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:39:43 by romain            #+#    #+#             */
/*   Updated: 2025/01/19 21:00:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 1;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if ('a' <= av[j][i] && av[j][i] <= 'z')
				std::cout << (char)(av[j][i] - 32);
			else
				std::cout << (char)av[j][i];
			i++;
		}
		j++;
	}
	std::cout << "" << std::endl;
	return (0);
}

