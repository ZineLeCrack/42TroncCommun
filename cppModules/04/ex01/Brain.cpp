/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:03:29 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 16:50:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain	&Brain::operator=(const Brain& src)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
		if (src._ideas[i].length() > 0)
			this->_ideas[i].assign(src._ideas[i]);
	return (*this);
}

const std::string	Brain::getIdea(unsigned int i)const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("There is only 100 ideas per brain.");
}

void	Brain::setIdea(unsigned int i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "There is only 100 ideas per brain." << std::endl;
	return ;
}
