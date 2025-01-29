/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:53:07 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 22:15:57 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl constructor called" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
	return ;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my " <<
	"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. " <<
	"You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!"
	<< std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. " <<
	"I\'ve been coming for years whereas you started working here since last month."
	<< std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr_complain[4])() =
	{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break ;
		}
	}
	return ;
}
