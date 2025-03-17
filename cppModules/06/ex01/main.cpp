/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:21 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 11:05:23 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	{
		std::cout << YELLOW "Test 1" RESET << std::endl;
		std::cout << std::endl;
		Data	data;

		data.id = 42;
		data.name = "Hello World !";

		uintptr_t n = Serializer::serialize(&data);
		Data	*ptr = Serializer::deserialize(n);

		std::cout << "Before:\t" << &data << std::endl << "After:\t"
		<< ptr << std::endl;
		std::cout << std::endl;
		if (&data == ptr)
			std::cout << GREEN ">>>>>>>>>>SUCCESS<<<<<<<<<<" RESET << std::endl;
		else
			std::cout << RED ">>>>>>>>>>FAILURE<<<<<<<<<<" RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 2" RESET << std::endl;
		std::cout << std::endl;
		Data	data;

		data.id = 2147483647;
		data.name = "42";

		uintptr_t n = Serializer::serialize(&data);
		Data	*ptr = Serializer::deserialize(n);

		std::cout << "Before:\t" << &data << std::endl << "After:\t"
		<< ptr << std::endl;
		std::cout << std::endl;
		if (&data == ptr)
			std::cout << GREEN ">>>>>>>>>>SUCCESS<<<<<<<<<<" RESET << std::endl;
		else
			std::cout << RED ">>>>>>>>>>FAILURE<<<<<<<<<<" RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 3" RESET << std::endl;
		std::cout << std::endl;
		Data	data;

		data.id = -2147483648;
		data.name = "lorem ipsum";

		uintptr_t n = Serializer::serialize(&data);
		Data	*ptr = Serializer::deserialize(n);

		std::cout << "Before:\t" << &data << std::endl << "After:\t"
		<< ptr << std::endl;
		std::cout << std::endl;
		if (&data == ptr)
			std::cout << GREEN ">>>>>>>>>>SUCCESS<<<<<<<<<<" RESET << std::endl;
		else
			std::cout << RED ">>>>>>>>>>FAILURE<<<<<<<<<<" RESET << std::endl;
	}
}
