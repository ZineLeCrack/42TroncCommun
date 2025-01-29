/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:44:33 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 18:46:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
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

	return (0);
}
