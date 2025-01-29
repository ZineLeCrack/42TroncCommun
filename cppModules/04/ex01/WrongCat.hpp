/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:35:30 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 15:49:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
	
	public:

		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& copy);
		~WrongCat();

		WrongCat	&operator=(const WrongCat& src);

		void	makeSound()const;
};

#endif

