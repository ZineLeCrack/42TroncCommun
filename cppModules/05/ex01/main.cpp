/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:04:38 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/21 10:44:24 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[31mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31mDecrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[31mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[31mIncrementing grade of " << a->getName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[33mDestructing b\033[0m" << std::endl;
			std::cout << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[33mDestructing b\033[0m" << std::endl;
			std::cout << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat("Bob", 120);
		std::cout << std::endl;
		std::cout << "\033[33mTesting a\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[33mConstructing b\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;
		std::cout << "\033[33mDestructing a\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		std::cout << std::endl;
		std::cout << "\033[33mTesting b\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;
		std::cout << "\033[33mDestructing b\033[0m" << std::endl;
		std::cout << std::endl;
		delete b;
		std::cout << std::endl;
	}
}
