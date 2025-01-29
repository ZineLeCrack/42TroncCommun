/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:52:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:49:57 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Unknown")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal for the type " << type << " constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << "WrongAnimal for the type " << this->_type << " copy constructor called"
	<< std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal for the type " << this->_type << " destructor called"
	<< std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& src)
{
	this->_type = src._type;
	std::cout << "WrongAnimal for the type " << this->_type << " assignation called"
	<< std::endl;
	return (*this);
}

void	WrongAnimal::makeSound()const
{
	std::cout << this->_type << " made a WrongAnimal sound!"
	<< std::endl;
	return ;
}

std::string	WrongAnimal::getType()const
{
	return (this->_type);
}
