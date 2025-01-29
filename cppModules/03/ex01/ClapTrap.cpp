/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:22:09 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:02:15 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("undefinied"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
	return ;
}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor for the name " << name << " called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor for " << this->_name << " called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_attackDamage > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target <<
		", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attacks, it's dead!"
		<< std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " doesn\'t have any energy point!"
		<< std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " doesn\'t have any attack damage!"
		<< std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " took " << amount << " damages, he has "
		<< this->_hitPoints << " hits points left!" << std::endl;
	}
	else if (this->_hitPoints > 0)
	{
		std::cout << this->_name << " died!" << std::endl;
		this->_hitPoints = 0;
	}
	else
		std::cout << this->_name << " already dead!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << " repairs itself of " << amount
		<< " hits point!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " can't repairs itself, it's dead!"
		<< std::endl;
	else
		std::cout << this->_name
		<< " can't repairs itself, it has no energy points left!" << std::endl;
	return ;
}
