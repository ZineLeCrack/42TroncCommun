/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:32 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:12:10 by romain           ###   ########.fr       */
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
		~Zombie();

		void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
