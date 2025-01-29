/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:06 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 16:56:00 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	{
		Point a;
		Point b(10, 0);
		Point c(0, 10);
		Point point(1, 1);

		std::cout << "The point (x = " << point.getX() << " y = " << point.getY() <<
		")\na (x = " << a.getX() << " y = " << a.getY() << ")\n" <<
		"b (x = " << b.getX() << " y = " << b.getY() << ")\n" <<
		"c (x = " << c.getX() << " y = " << c.getY() << ")\n" << std::endl;

		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}

	std::cout << std::endl;

	{
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(8.5, -9);

		std::cout << "The point (x = " << point.getX() << " y = " << point.getY() <<
		")\na (x= " << a.getX() << " y = " << a.getY() << ")\n" <<
		"b (x= " << b.getX() << " y = " << b.getY() << ")\n" <<
		"c (x= " << c.getX() << " y = " << c.getY() << ")\n" << std::endl;

		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}

	std::cout << std::endl;

	{
		Point a(1, 3);
		Point b(1, 1);
		Point c(4, 1);
		Point point1(2, 2);
		Point point2(3, 2);

		std::cout << "The point1 (x = " << point1.getX() << " y = " << point1.getY() <<
		")\nThe point2 (x = " << point2.getX() << " y = " << point2.getY() <<
		")\na (x= " << a.getX() << " y = " << a.getY() << ")\n" <<
		"b (x= " << b.getX() << " y = " << b.getY() << ")\n" <<
		"c (x= " << c.getX() << " y = " << c.getY() << ")\n" << std::endl;

		if (bsp(a, b, c, point1) == true)
			std::cout << "point1: TRUE" << std::endl;
		else
			std::cout << "point1: FALSE" << std::endl;
		if (bsp(a, b, c, point2) == true)
			std::cout << "point2: TRUE" << std::endl;
		else
			std::cout << "point2: FALSE" << std::endl;
	}

	return (0);
}
