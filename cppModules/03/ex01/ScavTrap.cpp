/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:11:33 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:04:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardingGate = false;
	std::cout << "ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_guardingGate = copy._guardingGate;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardingGate = false;
	std::cout << "ScavTrap Constructor for the name " << this->_name
	<< " called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_attackDamage > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attacks, it's dead!"
		<< std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " doesn\'t have any energy point!"
		<< std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " doesn\'t have any attack damage!"
		<< std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guardingGate == false)
	{
		this->_guardingGate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate!"
		<< std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate!"
		<< std::endl;
	return ;
}
