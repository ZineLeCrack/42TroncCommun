/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:23:46 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/27 14:21:35 by rlebaill         ###   ########.fr       */
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

#include <iostream>
#include <iterator>
#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	private:

	public:

		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(): std::stack<T>()
		{
			std::cout << "MutantStack default constructor called" << std::endl;
			return ;
		}

		MutantStack(const std::stack<T> &src) : std::stack<T>(src)
		{
			std::cout << "Copy Constructor called" << std::endl;
		}

		~MutantStack()
		{
			std::cout << "MutantStack destructor called" << std::endl;
			return ;
		}

		std::stack<T> &operator=(const std::stack<T> &src)
		{
			*this = src;
			return (*this);
		}

		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}

		iterator end()
		{
			return (std::stack<T>::c.end());
		}
};
