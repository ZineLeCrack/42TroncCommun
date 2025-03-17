/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:30:33 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/27 12:11:54 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0), _i(0), _lst(NULL)
{
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N): _N(N), _i(0)
{
	std::cout << "Span of size " << this->_N << " constructor called"
	<< std::endl;
	this->_lst = new int[this->_N];
	return ;
}

Span::Span(Span const &copy): _N(copy._N), _i(copy._i)
{
	std::cout << "Span copy constructor called" << std::endl;
	this->_lst = new int[this->_N];
	for (int i = 0; i < static_cast<int>(this->_N); i++)
		this->_lst[i] = copy._lst[i];
	return ;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	if (this->_lst)
		delete [] this->_lst;
	return ;
}

Span &Span::operator=(Span const &src)
{
	this->_N = src._N;
	this->_lst = src._lst;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_i < this->_N)
	{
		this->_lst[this->_i] = n;
		this->_i++;
	}
	else
		throw Span::SpanIsFullException();
	return ;
}

int		Span::shortestSpan()
{	
	if (this->_i < 2)
		throw Span::NotEnoughElementInSpan();
	else
	{
		std::set<int>	s;
		for (int i = 0; i < static_cast<int>(this->_i); i++)
			s.insert(this->_lst[i]);
		std::set<int>::iterator it1 = s.begin();
		std::set<int>::iterator it2 = it1;
		it2++;
		int	min = 2147483647;
		while (it2 != s.end())
		{
			if (*it2 - *it1 < min)
				min = *it2 - *it1;
			it1++;
			it2++;
		}
		return (min);
	}
	return (0);
}

int		Span::longestSpan()
{
	if (this->_i < 2)
		throw Span::NotEnoughElementInSpan();
	else
	{
		int	max = this->_lst[0];
		int	min = this->_lst[0];

		for (int i = 1; i < static_cast<int>(this->_i); i++)
		{
			if (this->_lst[i] > max)
				max = this->_lst[i];
			if (this->_lst[i] < min)
				min = this->_lst[i];
		}
		return (max - min);
	}
	return (0);
}

const char	*Span::SpanIsFullException::what() const throw()
{
	return ("Span is full !!!");
}

const char	*Span::NotEnoughElementInSpan::what() const throw()
{
	return ("Not enough element in span !!!");
}
