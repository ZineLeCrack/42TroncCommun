/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:15:26 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:26:15 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie constructor called" << std::endl;
	return ;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Zombie constructor called" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor called" << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
	return ;
}
