/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:22:58 by romain            #+#    #+#             */
/*   Updated: 2025/02/27 09:56:23 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
	{
		std::cout << YELLOW "Test 1" RESET << std::endl;
		std::cout << std::endl;
		std::list<int> lst;
		lst.push_back(41);
		lst.push_back(42);
		lst.push_back(43);
		std::list<int>::iterator	it = lst.end();
		try
		{
			it = easyfind(lst, 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
		it = lst.end();
		try
		{
			it = easyfind(lst, 40);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2" RESET << std::endl;
		std::cout << std::endl;
		std::vector<int> lst;
		lst.push_back(2147483647);
		lst.push_back(0);
		lst.push_back(-2147483648);
		std::vector<int>::iterator	it = lst.end();
		try
		{
			it = easyfind(lst, 2147483647);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
		it = lst.end();
		try
		{
			it = easyfind(lst, 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 3" RESET << std::endl;
		std::cout << std::endl;
		std::deque<int> lst;
		lst.push_back(-41);
		lst.push_back(-42);
		lst.push_back(-43);
		std::deque<int>::iterator	it = lst.end();
		try
		{
			it = easyfind(lst, -43);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
		it = lst.end();
		try
		{
			it = easyfind(lst, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		if (it != lst.end())
			std::cout << *it << " found" << std::endl;
	}
}
