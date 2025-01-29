/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:21:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:36:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("undefinied_clap_trap")
{
	this->_name = "undefinied";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor for the name " << this->_name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor for " << this->_name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hitPoints > 0)
		std::cout << "Hello i am a DiamondTrap named " << this->_name <<
		" and i am originated from the ClapTrap named " << ClapTrap::_name << "!" <<
		std::endl;
	else
		std::cout << "DiamondTrap " << this->_name <<
		" can't say anything because it's dead!" << std::endl;
}
