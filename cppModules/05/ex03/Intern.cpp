/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:59:16 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/25 12:28:44 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &copy)
{
	(void)copy;
	std::cout << "Intern copy constructor called" << std::endl;
	return ;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

const char *Intern::FormNameDoesNotExistException::what() const throw()
{
	return ("The form name does not exist !!!");
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] =
	{"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i;
	for (i = 0; i < 3; i++)
		if (name == forms[i])
			break ;
	switch (i)
	{
		case 0:
		{
			AForm *form = new ShrubberyCreationForm(target);
			std::cout << "shrubbery creation form created !" << std::endl;
			return (form);
		}
		case 1:
		{
			AForm *form = new RobotomyRequestForm(target);
			std::cout << "robotomy request form created !" << std::endl;
			return (form);
		}
		case 2:
		{
			AForm *form = new PresidentialPardonForm(target);
			std::cout << "presidential pardon form created !" << std::endl;
			return (form);
		}
		default:
		{
			throw FormNameDoesNotExistException();
			return (NULL);
		}
	}
}
