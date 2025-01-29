/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:44 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:46:12 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(std::string type): Animal(type)
{
	std::cout << "Dog for the type " << type << " constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog for the type " << this->_type << " copy constructor called"
	<< std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog& src)
{
	this->_type = src._type;
	std::cout << "Dog for the type " << this->_type << " assignation called"
	<< std::endl;
	return (*this);
}

void	Dog::makeSound()const
{
	std::cout << "Dog for the type " << this->_type << " says :\nWWOOOOOOFFFF!!"
	<< std::endl;
	return ;
}
