/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:43:52 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 16:11:04 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("undefinied"), _grade_to_sign(150), _grade_to_execute(150)
{
	this->_signed = false;
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const int grade_to_sign, const int grade_to_execute): _name("undefinied"), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_signed = false;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
	else
		std::cout << "Form constructor called without a name with sign-grade of "
		<< this->_grade_to_sign << " and execution-grade of " << this->_grade_to_execute << std::endl;
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute): _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_signed = false;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
	else
		std::cout << "Form Constructor called for " << this->getName() <<
		" with sign-grade of " << grade_to_sign << " and execution-grade of "
		<< grade_to_execute << std::endl;
}

Form::Form(Form const &copy): _name(copy._name), _grade_to_sign(copy._grade_to_execute), _grade_to_execute(copy._grade_to_execute)
{
	this->_signed = copy._signed;
	std::cout << "Form Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form	&Form::operator=(Form const &src)
{
	this->_signed = src.getIsSignedBool();
	return (*this);
}

const std::string Form::getName()const
{
	return (this->_name);
}

int	Form::getSignGrade()const
{
	return (this->_grade_to_sign);
}

int	Form::getExecGrade()const
{
	return (this->_grade_to_execute);
}

bool	Form::getIsSignedBool()const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_to_sign)
	{
		std::cout << bureaucrat.getName()
		<< " signed " << this->getName() << "." << std::endl;
		this->_signed = true;
	}
	else
		throw Bureaucrat::GradeTooLowException();
	return ;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high !!!");
};

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low !!!");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << a->getName() << (a->getIsSignedBool() == true ? " sined" : " not signed") << ", form with " << a->getSignGrade()
	<< " grade to sign and " << a->getExecGrade() << " grade to execute." << std::endl;
	return (o);
}
