/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:46:18 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 20:43:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType(void);
		void				setType(std::string type);
};

#endif
