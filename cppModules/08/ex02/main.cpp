/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:23:50 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/27 14:37:23 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::cout << YELLOW "Subject test:" RESET << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		MutantStack<int> mstack;
		std::cout << std::endl;
		std::cout << BLUE "push 5 and 17" RESET << std::endl;
		std::cout << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "pop 17" RESET << std::endl;
		mstack.pop();
		std::cout << std::endl;
		std::cout << BLUE "size" RESET << std::endl;
		std::cout << std::endl;
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "push 3, 5, 737 and 0" RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << std::endl;
		std::cout << BLUE "go from begin to end" RESET << std::endl;
		std::cout << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 1:" RESET << std::endl;
		std::cout << std::endl;
		std::cout << BLUE "constructing" RESET << std::endl;
		std::cout << std::endl;
		MutantStack<std::string> s;
		std::cout << std::endl;
		std::cout << BLUE "push \"Hello \", \"World \" and \"!\\n\" and testing" RESET << std::endl;
		std::cout << std::endl;
		s.push("Hello ");
		s.push("World ");
		s.push("!\n");
		MutantStack<std::string>::iterator b;
		MutantStack<std::string>::iterator e = s.end();
		for (b = s.begin(); b != e; b++)
			std::cout << *b;
		std::cout << std::endl;
		std::cout << BLUE "destructing" RESET << std::endl;
		std::cout << std::endl;
	}
}
