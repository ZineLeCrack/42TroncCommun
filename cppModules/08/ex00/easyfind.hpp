/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:09:41 by romain            #+#    #+#             */
/*   Updated: 2025/02/27 16:02:45 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <algorithm>
#include <iostream>

class NotFoundException: public std::exception
{
	public:

		virtual const char *what() const throw()
		{
			return ("not found !!!");
		}
};

template<typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator	it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end())
		throw NotFoundException();
	return (it);
}
