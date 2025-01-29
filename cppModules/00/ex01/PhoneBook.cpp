/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:36:59 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 17:13:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	// std::cout << "PhoneBook: Constructor called" << std::endl;
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBook: Destructor called" << std::endl;
	return ;
}

void	PhoneBook::add_contact()
{
	if (this->_index < 8)
	{
		this->_PhoneBook[this->_index].add_new();
		this->_index++;
	}
	else
	{
		for (int i = 1; i < 8; i++)
		{
			this->_PhoneBook[i - 1] = this->_PhoneBook[i];
		}
		this->_PhoneBook[7].add_new();
	}
}

void	PhoneBook::get_contact_infos()
{
	std::string input;

	while (1)
	{
		std::cout << "Choose a number between 1 and 8 :\n> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Ctrl D pressed, bye bye !" << std::endl;
			exit (0);
		}
		else if (input.length() == 0)
			std::cout << "You wrote nothing." << std::endl;
		else if (input.length() > 1)
			std::cout << "Too many characters." << std::endl;
		else if ('1' <= input[0] && input[0] <= '8')
		{
			if (this->_index < input[0] - '0')
				std::cout << "This contact does not exist." << std::endl;
			else
				break ;
		}
		else
			std::cout << "Input invalid." << std::endl;
	}
	std::cout << "You chose " << input << " :\n" << std::endl;
	this->_PhoneBook[input[0] - '0' - 1].get_infos(input[0] - '0');
	std::cout << std::endl;
	return ;
}
