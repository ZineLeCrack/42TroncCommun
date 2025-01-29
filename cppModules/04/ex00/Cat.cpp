/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:31 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:46:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout << "Cat for the type " << type << " constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Cat for the type " << this->_type << " copy constructor called"
	<< std::endl;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat& src)
{
	this->_type = src._type;
	std::cout << "Cat for the type " << this->_type << " assignation called"
	<< std::endl;
	return (*this);
}

void	Cat::makeSound()const
{
	std::cout << "Cat for the type " << this->_type << " says :\nMMEEEEOOOOWWWWWW!!"
	<< std::endl;
	return ;
}
