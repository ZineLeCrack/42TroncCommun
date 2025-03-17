/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:51 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/04 12:11:10 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "usage: ./PmergeMe <number> <number> <number> ..." << std::endl;
		return (1);
	}
	std::vector<int> Vec;
	std::deque<int> Deq;
	double vectorSortingTime;
	double dequeSortingTime;
	int number;
	std::cout << MAGENTA "Before:\t\t";
	for (int index = 1; index < argc; index++)
	{
		std::stringstream readstring(argv[index]);
		if (!(readstring >> number) || !(readstring.eof()))
		{
			std::cerr << "Error: fail to read arguments" << std::endl;
			return (1);
		}
		if (number < 0)
		{
			std::cerr << "Error: negative numbers are forbidden" << std::endl;
			return (1);
		}
		Vec.push_back(number);
		Deq.push_back(number);
		std::cout << number << " ";
	}
	std::cout << RESET << std::endl;
	caluclateTime(Vec, Deq , vectorSortingTime, dequeSortingTime);
	std::cout << std::endl;
	print(Vec, Deq);
	std::cout << std::endl;
	if (VectorIsSort(Vec))
		std::cout << YELLOW "vector after: " << std::endl << GREEN ">>>>>>>>>> SUCCESS <<<<<<<<<<" RESET << std::endl;
	else
		std::cout << YELLOW "vector after: " << std::endl << RED ">>>>>>>>>> FAILURE <<<<<<<<<<" RESET << std::endl;
	if (DequeIsSort(Deq))
		std::cout << YELLOW "deque  after: " << std::endl << GREEN ">>>>>>>>>> SUCCESS <<<<<<<<<<" RESET << std::endl;
	else
		std::cout << YELLOW "deque  after: " << std::endl << RED ">>>>>>>>>> FAILURE <<<<<<<<<<" RESET << std::endl;
	std::cout << std::endl << YELLOW "Time to process a range of " <<  argc - 1 <<  " elements with std::vector : " << vectorSortingTime << " us" << std::endl;
	std::cout << "Time to process a range of " <<  argc - 1 <<  " elements with std::deque :  " << dequeSortingTime << " us" RESET << std::endl;
}
