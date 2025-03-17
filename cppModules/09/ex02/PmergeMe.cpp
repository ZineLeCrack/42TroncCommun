/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:34:13 by rlebaill          #+#    #+#             */
/*   Updated: 2025/03/04 10:46:52 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)(other);}

void PmergeMe::mergeInsertSortVector(std::vector<int> &container, int start, int end)
{
	int newEnd;

	if (start < end)
	{
		if ((end - start) < 3)
			insertSortVector(container, start, end);
		else
		{
			newEnd = start + (end - start) / 2;
			mergeInsertSortVector(container,  start, newEnd);
			mergeInsertSortVector(container, newEnd + 1, end);
			mergeSortVector(container, start, newEnd, end);
		}
	}
}

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end)
{
	int i, j, k;

	std::vector<int> left(mid - start + 1);
	std::vector<int> right(end - mid);

	for(i = 0; i < (mid - start + 1); ++i)
		left[i] = container[start + i];
	for(j = 0; j < (end - mid); ++j)
		right[j] = container[mid + 1 + j];
	i = 0;
	j = 0;
	k = start;
	while(i < (mid - start + 1) && j < (end - mid))
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while(i < (mid - start + 1))
		container[k++] =  left[i++];
	while (j < (end - mid))
		container[k++] = right[j++];
}

void PmergeMe::insertSortVector(std::vector<int> &container, int start, int end)
{
	for(int index = start + 1; index <= end; index++)
	{
		int hold = container[index];
		int j = index - 1;
		for(; j >= start && container[j] > hold; --j)
			container[j + 1] = container[j];
		container[j + 1] = hold;
	}
}

void PmergeMe::runVector(std::vector<int> &container)
{
	mergeInsertSortVector(container, 0, container.size() - 1);
}

void PmergeMe::runDeque(std::deque<int> &container)
{
	mergeInsertSortDeque(container, 0, container.size() - 1);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &container, int start, int end)
{
	int newEnd;
	if (start < end)
	{
		if ((end - start) < 3)
			insertSortDeque(container, start, end);
		else
		{
			newEnd = start + (end - start) / 2;
			mergeInsertSortDeque(container,  start, newEnd);
			mergeInsertSortDeque(container, newEnd + 1, end);
			mergeSortDeque(container, start, newEnd, end);
		}
	}
}

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end)
{
	int i, j , k;

	std::deque<int> left(mid - start + 1);
	std::deque<int> right(end - mid);

	for(i = 0; i < (mid - start + 1); ++i)
		left[i] = container[start + i];
	for(j = 0; j < (end - mid); ++j)
		right[j] = container[mid + 1 + j];
	i = 0;
	j = 0;
	k = start;
	while(i < (mid - start + 1) && j < (end - mid))
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}

	while(i < (mid - start + 1))
		container[k++] =  left[i++];
	while (j < (end - mid))
		container[k++] = right[j++];
}

void PmergeMe::insertSortDeque(std::deque<int> &container, int start, int end)
{
	for(int index = start + 1; index <= end; index++)
	{
		int hold = container[index];
		int j = index - 1;
		for(; j >= start && container[j] > hold; --j)
			container[j + 1] = container[j];
		container[j + 1] = hold;
	}
}

void caluclateTime(std::vector<int> &Vcontainer, std::deque<int> &Dcontainer,double &vecTime, double &deqTime)
{
	std::clock_t start = std::clock();
	PmergeMe::runVector(Vcontainer);
	std::clock_t end = std::clock();
	double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
	vecTime = elapsed;
	start = std::clock();
	PmergeMe::runDeque(Dcontainer);
	end = std::clock();
	elapsed = static_cast<double> (end - start) / (CLOCKS_PER_SEC / 1000000.0);
	deqTime = elapsed;
}

void print(std::vector<int> &Vec, std::deque<int> &Deq)
{
	std::cout << BLUE "Vector " << "after:\t"; 
	typedef std::vector<int>::const_iterator Viterator;
	for (Viterator Vit = Vec.begin(); Vit != Vec.end(); ++Vit)
		std::cout << *Vit << " ";
	std::cout << std::endl;
	std::cout << CYAN "Deque " << " after:\t";
	typedef std::deque<int>::const_iterator Diterator;
	for (Diterator Dit = Deq.begin(); Dit != Deq.end(); ++Dit)
		std::cout << *Dit << " ";
	std::cout << std::endl;
}

int midPoint(int start, int end)
{
	return(start + (end - start) / 2);
}

int VectorIsSort(std::vector<int> &Vec)
{
	std::vector<int>::iterator it1 = Vec.begin();
	std::vector<int>::iterator it2 = it1;
	it2++;
	while (it2 != Vec.end())
	{
		if (*it1 > *it2)
			return (0);
		it1++;
		it2++;
	}
	return (1);
}

int DequeIsSort(std::deque<int> &Deq)
{
	std::deque<int>::iterator it1 = Deq.begin();
	std::deque<int>::iterator it2 = it1;
	it2++;
	while (it2 != Deq.end())
	{
		if (*it1 > *it2)
			return (0);
		it1++;
		it2++;
	}
	return (1);
}
