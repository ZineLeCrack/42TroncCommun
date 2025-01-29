/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:34:40 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:49:27 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:

		std::string	_type;
	
	public:

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);
		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal& src);

		void		makeSound()const;
		std::string	getType()const;
};

#endif

