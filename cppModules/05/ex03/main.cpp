/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:34:49 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/25 12:04:41 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[33mConstructing\033[0m" << std::endl;
	std::cout << std::endl;
	Bureaucrat	*b = new Bureaucrat("David", 1);
	Intern		*i = new Intern();
	std::cout << std::endl;
	std::cout << "\033[33mTesting\033[0m" << std::endl;
	std::cout << std::endl;
	AForm	*s = NULL, *r = NULL, *p = NULL, *a = NULL;
	try
	{
		s = i->makeForm("shrubbery creation", "home");
	}
	catch (Intern::FormNameDoesNotExistException &e)
	{
		std::cerr << "\033[31mCannot create ShrubberyCreationForm\033[0m"
		<< std::endl;
	}
	if (s)
	{
		b->signForm(*s);
		try
		{
			b->executeForm(*s);
		}
		catch (ShrubberyCreationForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< s->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	std::cout << std::endl;
	try
	{
		r = i->makeForm("robotomy request", "Bob");
	}
	catch (Intern::FormNameDoesNotExistException &e)
	{
		std::cerr << "\033[31mCannot create RobotomyRequestForm\033[0m"
		<< std::endl;
	}
	if (r)
	{
		b->signForm(*r);
		try
		{
			b->executeForm(*r);
		}
		catch (RobotomyRequestForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< r->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	std::cout << std::endl;
	try
	{
		p = i->makeForm("presidential pardon", "Harl");
	}
	catch (Intern::FormNameDoesNotExistException &e)
	{
		std::cerr << "\033[31mCannot create PresidentialPardonForm\033[0m"
		<< std::endl;
	}
	if (p)
	{
		b->signForm(*p);
		try
		{
			b->executeForm(*p);
		}
		catch (RobotomyRequestForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< p->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	std::cout << std::endl;
	try
	{
		a = i->makeForm("error request", "Chris");
	}
	catch (Intern::FormNameDoesNotExistException &e)
	{
		std::cerr << "\033[31mCannot create error request\033[0m"
		<< std::endl;
	}
	if (a)
	{
		b->signForm(*a);
		try
		{
			b->executeForm(*a);
		}
		catch (RobotomyRequestForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[33mDestructing\033[0m" << std::endl;
	std::cout << std::endl;
	delete i;
	delete b;
	if (s)
		delete s;
	if (r)
		delete r;
	if (p)
		delete p;
	if (a)
		delete a;
}
