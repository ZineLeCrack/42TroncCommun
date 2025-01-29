/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:45:42 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 21:02:53 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "Human A constructor called" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "Human A destructor called" << std::endl;
	return ;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with there "
	<< this->_weapon.getType() << std::endl;
	return ;
}
