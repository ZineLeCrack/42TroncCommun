/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:44:33 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 19:31:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap a;
		ClapTrap b("Leo");

		a.attack("Lola");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("Cyprien");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Elouann");
		b.beRepaired(3);
	}

	std::cout << std::endl;

	{
		ScavTrap c;
		ScavTrap d("Baptiste");

		c.attack("Leo");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Cyprien");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Elouann");
	}
	return (0);
}
