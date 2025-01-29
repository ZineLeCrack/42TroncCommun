/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:08 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:15:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
