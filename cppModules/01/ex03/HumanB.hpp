/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:46:55 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 21:08:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:

		std::string	_name;
		Weapon		*_weapon;

	public:

		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif
