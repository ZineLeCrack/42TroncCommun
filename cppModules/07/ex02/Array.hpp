/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:48:25 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:25 by rlebaill         ###   ########.fr       */
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

template <typename T>
class Array
{
	private:

		T 				*_array;
		unsigned int	_size;

	public:

		Array(): _size(0)
		{
			std::cout << "Array default constructor called" << std::endl;
			this->_array = new T[this->_size];
			return ;
		}

		Array(unsigned int size): _size(size)
		{
			std::cout << "Array for the length " << this->_size
			<< " constructor called" << std::endl;
			this->_array = new T[this->_size];
			return ;
		}

		Array(Array const &copy): _size(copy._size)
		{
			std::cout << "Array copy constructor called" << std::endl;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = copy._array[i];
			return ;
		}

		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			if (this->_array)
				delete [] this->_array;
			return ;
		}

		Array	&operator=(Array const &src)
		{
			if (this->_array)
				delete [] this->_array;
			this->_array = src._array;
			this->_size = src._size;
			return (*this);
		}

		T	&operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw OutOfRangeException();
			return (this->_array[index]);
		}

		unsigned int	size()
		{
			return (this->_size);
		}

		class OutOfRangeException: std::exception
		{
			public:

				virtual const char	*what() const throw()
				{
					return ("Error: index out of range !!!");
				}
		};
};
