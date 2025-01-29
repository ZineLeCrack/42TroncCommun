/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:04:19 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 16:43:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:

		const Fixed	_x;
		const Fixed	_y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point();

		Point	&operator=(const Point &src);

		const Fixed	&getX()const;
		const Fixed	&getY()const;
};

#endif
