/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:21:59 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/25 12:37:54 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("undefinied"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat for the name " << this->_name
	<< " and default grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("undefinied")
{
	this->setGrade(grade);
	std::cout << "Bureaucrat for a default name with the grade " << this->_grade
	<< " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	this->setGrade(grade);
	std::cout << "Bureaucrat for the name " << this->_name << " with the grade "
	<< this->_grade << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !!!");
}

const std::string	Bureaucrat::getName()const
{
	return (this->_name);
}

int	Bureaucrat::getGrade()const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	this->setGrade(this->_grade + 1);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << "." << std::endl;
	return (o);
}
