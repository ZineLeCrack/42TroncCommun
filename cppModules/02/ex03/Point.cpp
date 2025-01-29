/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:04:23 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 16:45:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	Fixed	x;
	Fixed	y;

//	std::cout << "Point constructor called" << std::endl;
	return ;
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
//	std::cout << "Point constructor called" << std::endl;
	return ;
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
//	std::cout << "Point copy constructor called" << std::endl;
	*this = copy;
	return ;	
}

Point::~Point()
{
//	std::cout << "Point destructor called" << std::endl;
	return ;
}

Point	&Point::operator=(const Point &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

const Fixed	&Point::getX()const
{
	return (this->_x);
}

const Fixed	&Point::getY()const
{
	return (this->_y);
}
