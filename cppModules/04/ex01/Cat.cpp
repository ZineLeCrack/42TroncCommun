/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:31 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 17:05:20 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_ideas = new Brain();
	return ;
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout << "Cat for the type " << type << " constructor called" << std::endl;
	this->_ideas = new Brain();
	return ;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Cat for the type " << this->_type << " copy constructor called"
	<< std::endl;
	*this = copy;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_ideas;
	return ;
}

Cat	&Cat::operator=(const Cat& src)
{
	this->_type = src._type;
	this->_ideas = new Brain();
	*this->_ideas = *src._ideas;
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

void	Cat::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "Idea " << i << " of the cat is: \"" <<
		this->_ideas->getIdea(i) << "\"" << std::endl;
	return ;
}

void	Cat::setIdea(unsigned int i, std::string idea)const
{
	this->_ideas->setIdea(i, idea);
	return ;
}
