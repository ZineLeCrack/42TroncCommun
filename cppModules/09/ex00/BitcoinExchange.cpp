/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:06:51 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/03 13:12:21 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *file)
{
	std::ifstream	infile;

	infile.open(file);
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		std::string date = line.substr(0, 10);
		this->_map[date] = atof(&(line.c_str())[11]);
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy): _map(copy._map) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	this->_map = src._map;
	return (*this);
}

std::map<std::string, float> &BitcoinExchange::getMap()
{
	return (this->_map);
}

int	getDayMax(int y, int m)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return (31);
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		return (30);
	else if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
		return (29);
	else
		return (28);
}

int	isValid(std::string const date)
{
	
	if (date.size() != 10)
		return (0);
	if (!isdigit(date[0])
		|| !isdigit(date[1])
		|| !isdigit(date[2])
		|| !isdigit(date[3])
		|| date[4] != '-'
		|| !isdigit(date[5])
		|| !isdigit(date[6])
		|| date[7] != '-'
		|| !isdigit(date[8])
		|| !isdigit(date[9]))
		return (0);
	int	y = atoi(date.substr(0, 4).c_str());
	if (y > 2025 || y < 2009)
		return (0);
	int	m = atoi(date.substr(5, 2).c_str());
	if (m > 12 || m < 1)
		return (0);
	int d = atoi(date.substr(8, 2).c_str());
	if (d > getDayMax(y, m) || d < 1)
		return (0);
	if (y == 2009 && m == 1 && d == 1)
		return (0);
	return (1);
}

float	BitcoinExchange::getValue(std::string const date, float n)
{
	if (!isValid(date))
		throw DateNotValidException();
	if (n < 0)
		throw NotAPostiveNumberException();
	if (n > 1000)
		throw TooLargeNumberException();
	std::map<std::string, float>::iterator it1;
	for (it1 = this->getMap().begin(); it1 != this->getMap().end(); it1++)
	{
		if (((atoi(date.substr(0, 4).c_str()) == atoi(it1->first.substr(0, 4).c_str())
		&&  atoi(date.substr(5, 2).c_str()) == atoi(it1->first.substr(5, 2).c_str())
		&&  atoi(date.substr(8, 2).c_str()) <= atoi(it1->first.substr(8, 2).c_str())))
		|| ((atoi(date.substr(0, 4).c_str()) == atoi(it1->first.substr(0, 4).c_str())
		&&  atoi(date.substr(5, 2).c_str()) < atoi(it1->first.substr(5, 2).c_str())))
		|| ((atoi(date.substr(0, 4).c_str()) < atoi(it1->first.substr(0, 4).c_str()))))
		{
			if (!(atoi(date.substr(0, 4).c_str()) == atoi(it1->first.substr(0, 4).c_str())
			&&  atoi(date.substr(5, 2).c_str()) == atoi(it1->first.substr(5, 2).c_str())
			&&  atoi(date.substr(8, 2).c_str()) == atoi(it1->first.substr(8, 2).c_str())))
				it1--;
			return (it1->second * n);
		}
	}
	throw DateNotValidException();
}
