/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:57:44 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 16:58:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_ideas = new Brain();
	return ;
}

Dog::Dog(std::string type): Animal(type)
{
	std::cout << "Dog for the type " << type << " constructor called" << std::endl;
	this->_ideas = new Brain();
	return ;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog for the type " << this->_type << " copy constructor called"
	<< std::endl;
	*this = copy;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_ideas;
	return ;
}

Dog	&Dog::operator=(const Dog& src)
{
	this->_type = src._type;
	this->_ideas = new Brain();
	*this->_ideas = *src._ideas;
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

void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "Idea " << i << " of the dog is: \"" <<
		this->_ideas->getIdea(i) << "\"" << std::endl;
	return ;
}

void	Dog::setIdea(unsigned int i, std::string idea)const
{
	this->_ideas->setIdea(i, idea);
	return ;
}
