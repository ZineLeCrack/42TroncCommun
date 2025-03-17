/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:54 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/03 12:47:46 by rlebaill         ###   ########.fr       */
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

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
	private:

		BitcoinExchange();

		std::map<std::string, float> _map;

	public:

		BitcoinExchange(const char *file);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &src);

		std::map<std::string, float>	&getMap();

		float			getValue(std::string const date, float n);

		class DateNotValidException: std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: invalide date");
				}
		};

		class NotAPostiveNumberException: std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};

		class TooLargeNumberException: std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: too large number.");
				}
		};
};
