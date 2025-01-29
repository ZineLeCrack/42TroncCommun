/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:39:50 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 17:08:56 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << "\033[33m-------------------------TEST PART--------------------------\033[0m"
	<< std::endl;
	std::cout << std::endl;
	{
		const Animal*	meta[5];

		for (int i = 0; i < 5; i++)
		{
			if (i % 2 == 0)
				meta[i] = new Cat();
			else
				meta[i] = new Dog();
		}
		for (int j = 0; j < 5; j++)
		{
			std::cout << "Animal _type: " << meta[j]->getType() << std::endl;
			meta[j]->makeSound();
		}
		for (int k = 0; k < 5; k++)
			delete meta[k];
	}
	std::cout << std::endl;
	std::cout << "\033[33m-------------------------COPY TEST--------------------------\033[0m"
	<< std::endl;
	std::cout << std::endl;
	{
		const Cat*	cat = new Cat("cat");
		const Dog*	dog = new Dog("dog");

		cat->setIdea(0, "I love mice!");
		cat->setIdea(1, "I love birds!");
		cat->setIdea(2, "I love rats!");
		cat->getIdeas();
		dog->setIdea(0, "I have to smell it...");
		dog->setIdea(1, "I have to pee on it...");
		dog->setIdea(2, "I have to smell it again...");
		dog->getIdeas();
		std::cout << "\n\t\033[33mAssignation copy!\033[0m" << std::endl;
		const Dog*	a = dog;
		a->getIdeas();
		std::cout << "\n\t\033[33mCopy constructor!\033[0m" << std::endl;
		const Cat*	b = new Cat(*cat);
		b->getIdeas();
		std::cout << std::endl;
		delete cat;
		delete dog;
		delete b;
	}
	return (0);
}