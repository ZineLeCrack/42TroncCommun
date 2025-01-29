/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:53:10 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 22:05:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:

		void	debug();
		void	info();
		void	warning();
		void	error();

	public:

		Harl();
		~Harl();

		void	complain(std::string level);
	
};

#endif
