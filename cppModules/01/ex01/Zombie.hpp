/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:10:31 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:19:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:

		std::string	_name;

	public:

		Zombie(std::string name);
		Zombie();
		~Zombie();

		void	announce();
		void	set_name(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif

