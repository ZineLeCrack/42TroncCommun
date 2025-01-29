/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:45:50 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 21:08:32 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "Human B constructor called" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "Human B destructor called" << std::endl;
	return ;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with theire "
	<< this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}
