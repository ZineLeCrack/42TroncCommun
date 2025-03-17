/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:07:03 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/03 13:03:12 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage : ./btc <file_name>" << std::endl;
		return (1);
	}
	std::ifstream	infile;

	infile.open(av[1]);
	if (infile.fail())
	{
		std::cerr << "Error: failed to open file" << std::endl;
	}
	std::string line;
	std::getline(infile, line);
	BitcoinExchange	btc("data.csv");
	while (std::getline(infile, line))
	{
		if (line.find('|') == std::string::npos || line.find_last_of("01234456789") < line.find('|'))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
		else
		{
			std::string date = line.substr(0, line.find_first_of(" \t|"));
			float n = atof(line.substr((1 + line.find_first_of('|'))).c_str());
			try
			{
				float value = btc.getValue(date, n);
				std::cout << date << " => " << n << " = " << value << std::endl;
			}
			catch (BitcoinExchange::DateNotValidException &e)
			{
				std::cerr << e.what() << " => " << date << std::endl;
			}
			catch (BitcoinExchange::NotAPostiveNumberException &e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch (BitcoinExchange::TooLargeNumberException &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}
