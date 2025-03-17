/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:26:21 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/27 12:21:46 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		std::cout << YELLOW "Subject test:" RESET << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Span sp = Span(5);
		std::cout << std::endl;
		std::cout << BLUE "testing" RESET << std::endl;
		std::cout << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 1:" RESET << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Span sp = Span(5);
		std::cout << std::endl;
		std::cout << BLUE "adding 5 elements" RESET << std::endl;
		for (int i = -2; i < 23; i += 5)
		{
			try
			{
				sp.addNumber(i);
			}
			catch(const Span::SpanIsFullException &e)
			{
				std::cerr << RED << e.what() << RESET << '\n';
			}
		}
		std::cout << std::endl;
		std::cout << BLUE "adding a 6th element" RESET << std::endl;
		std::cout << std::endl;
		try
		{
			sp.addNumber(42);
		}
		catch(const Span::SpanIsFullException &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		std::cout << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2:" RESET << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Span sp = Span(50000);
		std::cout << std::endl;
		std::cout << BLUE "testing with 0 element" RESET << std::endl;
		std::cout << std::endl;
		try
		{
			sp.shortestSpan();
		}
		catch(const Span::NotEnoughElementInSpan &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		try
		{
			sp.longestSpan();
		}
		catch(const Span::NotEnoughElementInSpan &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		std::cout << std::endl;
		std::cout << BLUE "testing with 1 element" RESET << std::endl;
		std::cout << std::endl;
		try
		{
			sp.addNumber(-25000);
		}
		catch(const Span::SpanIsFullException &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		try
		{
			sp.shortestSpan();
		}
		catch(const Span::NotEnoughElementInSpan &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		try
		{
			sp.longestSpan();
		}
		catch(const Span::NotEnoughElementInSpan &e)
		{
			std::cerr << RED << e.what() << RESET << '\n';
		}
		std::cout << std::endl;
		std::cout << BLUE "ading 50,000 elements" RESET << std::endl;
		for (int i = -24999; i < 25000; i++)
		{
			try
			{
				sp.addNumber(i);
			}
			catch(const Span::SpanIsFullException &e)
			{
				std::cerr << RED << e.what() << RESET << '\n';
			}
		}
		std::cout << std::endl;
		std::cout << BLUE "testing with 50,000 elements" RESET << std::endl;
		std::cout << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
}
