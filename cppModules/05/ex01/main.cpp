/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:04:38 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 12:17:58 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat("David", 5);
		Form *b = new Form("Form", 5, 5);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign "
			<< b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << b;
		std::cout << std::endl;
		std::cout << "\033[33mDestructing\033[0m" << std::endl;
		std::cout << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "\033[33m-------------------------------------------------------\033[0m" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat("Harl", 145);
		Bureaucrat *b = new Bureaucrat("Chris", 1);
		Form *c = new Form("Contract", 140, 100);
		std::cout << std::endl;
		std::cout << "\033[33mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			// c->beSigned(*a);
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << c;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[31m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << c;
		b->signForm(*c);
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
		Form *a = NULL;
		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[31mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[33mDeconstructing\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	return (0);
}
