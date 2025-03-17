/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:39:37 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 16:19:31 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	{
		std::cout << YELLOW "Subject test" RESET << std::endl;
		std::cout << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 1: int" RESET << std::endl;
		std::cout << std::endl;
		int a = 5, b = 10;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2: unsigned int" RESET << std::endl;
		std::cout << std::endl;
		unsigned int a = 4294967295, b = 42;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 3: long" RESET << std::endl;
		std::cout << std::endl;
		long a = 2147483647, b = -42;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 4: long long" RESET << std::endl;
		std::cout << std::endl;
		long long a = 0, b = 9223372036854775807;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 5: char" RESET << std::endl;
		std::cout << std::endl;
		char a = 53, b = 55;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 6: unsigned char" RESET << std::endl;
		std::cout << std::endl;
		unsigned char a = 50, b = 57;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 7: void *" RESET << std::endl;
		std::cout << std::endl;
		void *a = (void *)2, *b = (void *)1;
		std::cout << BLUE "swap" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "Before:\ta = " << a << "\tb = " << b << std::endl;
		swap(a, b);
		std::cout << "After:\ta = " << a << "\tb = " << b << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "max/min" RESET << std::endl;
		std::cout << std::endl;
		std::cout << "The greater between " << a << " and " << b << " is: "
		<< max(a, b) << std::endl;
		std::cout << "The smaller between " << a << " and " << b << " is: "
		<< min(a, b) << std::endl;
	}
}
