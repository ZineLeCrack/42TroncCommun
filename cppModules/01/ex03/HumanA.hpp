/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:46:27 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 21:04:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack();
};

#endif
