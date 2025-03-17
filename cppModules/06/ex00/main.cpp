/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:51:38 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 09:23:11 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	ScalarConverter *n = NULL;

	if (ac != 2)
	{
		std::cerr << "This program take 1 argument" << std::endl;
		return (1);
	}
	try
	{
		n = new ScalarConverter(av[1]);
	}
	catch (ScalarConverter::ErrorException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (n)
		delete n;
	return (0);
}
