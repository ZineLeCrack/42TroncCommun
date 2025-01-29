/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:46:06 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 20:43:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon constructor called" << std::endl;
	return ;
}

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
	return ;
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
