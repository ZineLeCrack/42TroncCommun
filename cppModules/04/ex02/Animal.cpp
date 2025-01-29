/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:30:26 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:51:14 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Unknown")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal for the type " << type << " constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& copy)
{
	this->_type = copy._type;
	std::cout << "Animal for the type " << this->_type << " copy constructor called"
	<< std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal for the type " << this->_type << " destructor called"
	<< std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal& src)
{
	this->_type = src._type;
	std::cout << "Animal for the type " << this->_type << " assignation called"
	<< std::endl;
	return (*this);
}

void	Animal::makeSound()const
{
	std::cout << "Animal for the type " << this->_type << " made a sound!"
	<< std::endl;
	return ;
}

std::string	Animal::getType()const
{
	return (this->_type);
}
