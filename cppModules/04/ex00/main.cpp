/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:39:50 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:55:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	std::cout << "\033[33m-------------------------TEST  PART-------------------------\033[0m"
	<< std::endl;
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	std::cout << "\033[31m-------------------------WRONG PART-------------------------\033[0m"
	<< std::endl;
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
	}
	return (0);
}