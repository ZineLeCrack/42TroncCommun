/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:32:46 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/04 12:12:35 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream> // readstream
// #include <cstddef>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class PmergeMe
{
	private:

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		static void mergeInsertSortVector(std::vector<int> &container, int start, int end);
		static void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
		static void insertSortVector(std::vector<int> &container, int start, int end);
		static void mergeInsertSortDeque(std::deque<int> &container, int start, int end);
		static void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
		static void insertSortDeque(std::deque<int> &container, int start, int end);
		static void runVector(std::vector<int> &container);
		static void runDeque(std::deque<int> &container);
};

void print(std::vector<int> &, std::deque<int> &);
void caluclateTime(std::vector<int> &, std::deque <int> &, double &, double &);
int midPoint(int start, int end);
int VectorIsSort(std::vector<int> &Vec);
int DequeIsSort(std::deque<int> &Deq);
