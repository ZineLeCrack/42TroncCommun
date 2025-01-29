/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:53:04 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 11:16:38 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	levels_to_int(char *av)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == av)
			return (i);
	return (-1);
}

void	harl_switch(char *av, Harl &harl)
{
	switch (levels_to_int(av))
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}

int	main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(av[1], harl);
	return (0);
}
