/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:13 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 16:57:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
	
		Brain*	_ideas;
	
	public:

		Cat();
		Cat(std::string type);
		Cat(const Cat& copy);
		~Cat();

		Cat	&operator=(const Cat& src);

		void	makeSound()const;
		void	getIdeas(void)const;
		void	setIdea(unsigned int i, std::string idea)const;
};

#endif
