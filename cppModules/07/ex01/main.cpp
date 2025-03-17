/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:20:27 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 16:35:08 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	ft_print(std::string &str)
{
	std::cout << str;
}

int main()
{
	{
		std::cout << YELLOW "Test 1: \"Hello World !\"" RESET << std::endl;
		std::cout << std::endl;
		std::string	array[3] =
		{"Hello ", "World ", "!\n"};
		::iter(array, 3, ft_print);
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2: \"Hello World !\"" RESET << std::endl;
		std::cout << std::endl;
		std::string	array[14] =
		{"H", "e", "l", "l", "o", " ", "W", "o", "r", "l", "d", " ", "!", "\n"};
		::iter(array, 14, ft_print);
	}
}
