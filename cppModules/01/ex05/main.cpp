/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:53:04 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 22:18:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl;

	std::cout << "ERROR -> Harl says :" << std::endl;
	harl.complain("ERROR");
	std::cout << "DEBUG -> Harl says :" << std::endl;
	harl.complain("DEBUG");
	return (0);
}
