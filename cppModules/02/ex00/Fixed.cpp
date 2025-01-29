/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:12 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 12:38:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}
