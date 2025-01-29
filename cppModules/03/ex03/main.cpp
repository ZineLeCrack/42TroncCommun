/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:44:33 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:32:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

	std::cout << std::endl;

	{
		FragTrap e;
		FragTrap f("Elouann");

		e.attack("Cyprien");
		e.highFiveGuys();
		e.beRepaired(22);
		e.takeDamage(21);
		e.beRepaired(22);
		f.attack("Baptiste");
		f.highFiveGuys();
		f.takeDamage(101);
		f.highFiveGuys();
		f.takeDamage(15);
		f.attack("Leo");
	}

	std::cout << std::endl;

	{
		DiamondTrap g;
		DiamondTrap h("Cyprien");

		g.attack("Baptiste");
		g.whoAmI();
		g.beRepaired(22);
		g.takeDamage(21);
		g.beRepaired(22);
		h.attack("Leo");
		h.whoAmI();
		h.takeDamage(101);
		h.whoAmI();
		h.takeDamage(15);
		h.attack("Lola");
	}

	return (0);
}
