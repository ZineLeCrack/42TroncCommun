/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:36:08 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 17:30:48 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	{
		std::cout << YELLOW "Test 1" RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Array<int> a(5);
		std::cout << std::endl;
		std::cout << BLUE "testing" RESET << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
			a[i] = i + 1;
		for (int i = 0; i < 5; i++)
			std::cout << a[i] << std::endl;
		std::cout << std::endl;
		std::cout << "size = " << a.size() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2" RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Array<char> a(15);
		char	str[15] = "Hello World !\n";
		std::cout << std::endl;
		std::cout << BLUE "testing" RESET << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 15; i++)
			a[i] = str[i];
		for (int i = 0; i < 15; i++)
			std::cout << a[i];
		std::cout << std::endl;
		std::cout << "size = " << a.size() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 3" RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Array<std::string> a(3);
		std::string	strings[3] = {"lorem", "ipsum", "dolor"};
		std::cout << std::endl;
		std::cout << BLUE "testing" RESET << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 3; i++)
			a[i] = strings[i];
		for (int i = 0; i < 3; i++)
			std::cout << a[i] << std::endl;
		std::cout << std::endl;
		std::cout << "size = " << a.size() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 4" RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		Array<std::string> a(3);
		std::string	strings[3] = {"lorem", "ipsum", "dolor"};
		std::cout << std::endl;
		std::cout << BLUE "testing" RESET << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 3; i++)
			a[i] = strings[i];
		try
		{
			a[4];
		}
		catch (Array<std::string>::OutOfRangeException &e)
		{
			std::cerr << RED "Cannot access to this value : " << e.what()
			<< RESET << std::endl;
		}
		std::cout << std::endl;
		std::cout << "size = " << a.size() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
}
