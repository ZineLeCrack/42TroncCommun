/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:27:08 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/27 12:01:59 by rlebaill         ###   ########.fr       */
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

#include <iterator>
#include <set>
#include <iostream>

class Span
{
	private:

		unsigned int	_N;
		unsigned int	_i;
		int				*_lst;

		Span();

	public:

		Span(unsigned int N);
		Span(Span const &copy);
		~Span();

		Span	&operator=(Span const &src);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		class SpanIsFullException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NotEnoughElementInSpan: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};
