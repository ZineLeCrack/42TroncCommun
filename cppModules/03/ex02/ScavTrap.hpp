/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:09:20 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:20:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

		bool _guardingGate;

	public:

		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
