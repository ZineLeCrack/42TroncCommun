/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:57:36 by romain            #+#    #+#             */
/*   Updated: 2025/01/29 16:46:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:

		std::string	_ideas[100];

	public:

		Brain();
		Brain(const Brain& copy);
		virtual ~Brain();
		
		Brain	&operator=(const Brain& src);
		
		const std::string	getIdea(unsigned int i)const;
		void 				setIdea(unsigned int i, std::string idea);
};

#endif
