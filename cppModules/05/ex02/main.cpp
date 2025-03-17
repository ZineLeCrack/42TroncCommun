/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:34:49 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/25 13:02:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat *b = new Bureaucrat("Bob", 140);
		Bureaucrat *c = new Bureaucrat("Leo", 130);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			c->executeForm(*a);
		}
		catch (ShrubberyCreationForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->signForm(*a);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to sign "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		try
		{
			c->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		AForm *a = new RobotomyRequestForm("Chris");
		Bureaucrat *b = new Bureaucrat("Bob", 70);
		Bureaucrat *c = new Bureaucrat("Leo", 40);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			c->executeForm(*a);
		}
		catch (RobotomyRequestForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->signForm(*a);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to sign "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		try
		{
			c->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		delete b;
		delete c;
	std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		AForm *a = new PresidentialPardonForm("Harl");
		Bureaucrat *b = new Bureaucrat("Bob", 20);
		Bureaucrat *c = new Bureaucrat("Leo", 5);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			c->executeForm(*a);
		}
		catch (PresidentialPardonForm::IsNotSignedException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->signForm(*a);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to sign "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << a;
		try
		{
			b->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		try
		{
			c->executeForm(*a);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << c->getName() << " was not able to execute "
			<< a->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		delete b;
		delete c;
	}
}
