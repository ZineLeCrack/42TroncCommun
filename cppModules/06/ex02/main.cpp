/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:12:03 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 13:06:10 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	randint(int a, int b)
{
	std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<int> dist(a, b);
	return (dist(gen));
}

Base	*generate(void)
{
	int rd = randint(0, 2);

	switch (rd)
	{
		case 0:
		{
			Base *a = new A();
			std::cout << "instance of type A created." << std::endl;
			return (a);
		}
		case 1:
		{
			Base *b = new B();
			std::cout << "instance of type B created." << std::endl;
			return (b);
		}
		default:
		{
			Base *c = new C();
			std::cout << "instance of type C created." << std::endl;
			return (c);
		}
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the type of the instance is A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "the type of the instance is B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "the type of the instance is C." << std::endl;
}

void	identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "the type of the instance is A." << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "the type of the instance is B." << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "the type of the instance is C." << std::endl;
}

int main()
{
	{
		std::cout << YELLOW "Test 1" RESET << std::endl;
		std::cout << std::endl;
		Base	*a = generate();

		identify(a);
		identify(*a);
		delete a;
	{
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	}
		std::cout << YELLOW "Test 2" RESET << std::endl;
		std::cout << std::endl;
		Base	*b = generate();

		identify(b);
		identify(*b);
		delete b;
	}
	std::cout << std::endl;
	std::cout << YELLOW "-------------------------------------------------------" RESET << std::endl;
	std::cout << std::endl;
	{
		std::cout << YELLOW "Test 3" RESET << std::endl;
		std::cout << std::endl;
		Base	*c = generate();

		identify(c);
		identify(*c);
		delete c;
	}
}
