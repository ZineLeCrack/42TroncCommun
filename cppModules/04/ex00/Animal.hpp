/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:28:10 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:47:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:

		std::string	_type;
	
	public:

		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);
		virtual ~Animal();

		Animal	&operator=(const Animal& src);

		virtual void	makeSound()const;
		std::string		getType()const;
};

#endif
