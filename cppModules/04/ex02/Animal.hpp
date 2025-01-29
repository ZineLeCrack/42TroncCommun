/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:28:10 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 17:17:38 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:

		std::string	_type;
		Animal(std::string type);
		Animal(const Animal& copy);
		Animal();
	
	public:

		virtual ~Animal();

		Animal	&operator=(const Animal& src);

		virtual void	makeSound()const;
		std::string		getType()const;
};

#endif
