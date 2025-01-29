/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:10:03 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:27:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	size = 42;

	Zombie	*horde = zombieHorde(size, "Michael");
	
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << " > ";
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
