/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:13 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:46:08 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	private:
	
	public:

		Cat();
		Cat(std::string type);
		Cat(const Cat& copy);
		~Cat();

		Cat	&operator=(const Cat& src);

		void	makeSound()const;
};

#endif
