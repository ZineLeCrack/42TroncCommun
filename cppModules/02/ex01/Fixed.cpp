/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:12 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 14:25:38 by romain           ###   ########.fr       */
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

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fp_value = roundf(n * (1 << this->_fract_bits));
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_value = (n << this->_fract_bits);
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

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int	Fixed::getRawBits(void)const
{
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt()const
{
	return (this->_fp_value >> this->_fract_bits);
}
