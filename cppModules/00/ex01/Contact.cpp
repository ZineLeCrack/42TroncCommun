/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:33:50 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 17:13:04 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	// std::cout << "Contact: Constructor called" << std::endl;
	this->_field_name[0] = "First Name";
	this->_field_name[1] = "Last Name";
	this->_field_name[2] = "Nickname";
	this->_field_name[3] = "Phone Number";
	this->_field_name[4] = "Darkest Secret";
	return ;
}

Contact::~Contact()
{
	// std::cout << "Contact: Destructor called" << std::endl;
	return ;
}

void	Contact::get_infos(int index)
{
	int	len;

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|         " << index << "|";
	for (int i = 0; i < 3; i++)
	{
		len = this->_info[i].length();
		if (len <= 10)
		{
			while (len++ < 10)
				std::cout << " ";
			std::cout << this->_info[i] << "|";
		}
		else
		{
			for (int j = 0; j < 9; j++)
				std::cout << this->_info[i][j];
			std::cout << ".|";
		}
	}
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	return ;
}

void	Contact::add_new()
{
	std::string	input;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter the " << this->_field_name[i] << " :\n> ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Ctrl D pressed, bye bye !" << std::endl;
			exit (0);
		}
		this->_info[i] = input;
	}
}
