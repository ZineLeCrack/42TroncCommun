/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:57:27 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 17:13:27 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Write a command (ADD, SEARCH, EXIT) :\n> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Ctrl D pressed, bye bye !" << std::endl;
			exit (0);
		}
		if (input.compare("ADD") == 0)
			PhoneBook.add_contact();
		else if (input.compare("SEARCH") == 0)
			PhoneBook.get_contact_infos();
		else if (input.compare("EXIT") == 0)
			break ;
	}
	std::cout << "Bye, bye !" << std::endl;
	return (0);
}
