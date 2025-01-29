/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:35:59 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:49:04 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout << "WrongCat for the type " << type << " constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << "WrongCat for the type " << this->_type << " copy constructor called"
	<< std::endl;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat& src)
{
	this->_type = src._type;
	std::cout << "WrongCat for the type " << this->_type << " assignation called"
	<< std::endl;
	return (*this);
}

void	WrongCat::makeSound()const
{
	std::cout << this->_type << " made a WrongCat sound!"
	<< std::endl;
	return ;
}
