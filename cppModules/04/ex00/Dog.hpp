/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:56:43 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:46:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	private:
	
	public:

		Dog();
		Dog(std::string type);
		Dog(const Dog& copy);
		~Dog();

		Dog	&operator=(const Dog& src);

		void	makeSound()const;
};

#endif