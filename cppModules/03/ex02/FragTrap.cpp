/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:42:46 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:03:38 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "FragTrap Constructor for the name " << this->_name
	<< " called" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_attackDamage > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " can't attacks, it's dead!"
		<< std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "FragTrap " << this->_name << " doesn\'t have any energy point!"
		<< std::endl;
	else
		std::cout << "FragTrap " << this->_name << " doesn\'t have any attack damage!"
		<< std::endl;
	return ;
}


void	FragTrap::highFiveGuys()
{
	if (this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name
		<< ": Can I have a high five ?\n*CLAP*\nThank you!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " can't ask you a high five, it's dead!"
		<< std::endl;
	return ;
}
