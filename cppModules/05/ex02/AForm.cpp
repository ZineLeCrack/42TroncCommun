/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:52:21 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 16:11:26 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("undefinied"), _grade_to_sign(150), _grade_to_execute(150)
{
	this->_signed = false;
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const int grade_to_sign, const int grade_to_execute): _name("undefinied"), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_signed = false;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
	else
		std::cout << "AForm constructor called without a name with sign-grade of "
		<< this->_grade_to_sign << " and execution-grade of " << this->_grade_to_execute << std::endl;
}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute): _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_signed = false;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
	else
		std::cout << "AForm Constructor called for " << this->getName() <<
		" with sign-grade of " << grade_to_sign << " and execution-grade of "
		<< grade_to_execute << std::endl;
}

AForm::AForm(AForm const &copy): _name(copy._name), _grade_to_sign(copy._grade_to_execute), _grade_to_execute(copy._grade_to_execute)
{
	this->_signed = copy._signed;
	std::cout << "AForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm	&AForm::operator=(AForm const &src)
{
	this->_signed = src.getIsSignedBool();
	return (*this);
}

const std::string AForm::getName()const
{
	return (this->_name);
}

int	AForm::getSignGrade()const
{
	return (this->_grade_to_sign);
}

int	AForm::getExecGrade()const
{
	return (this->_grade_to_execute);
}

bool	AForm::getIsSignedBool()const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high !!!");
};

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low !!!");
};

void	AForm::execute(Bureaucrat const & executor)const
{
	std::cout << executor.getName() << " executed nothing." << std::endl;
}

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << a->getName() << (a->getIsSignedBool() == true ? " sined" : " not signed") << ", form with " << a->getSignGrade()
	<< " grade to sign and " << a->getExecGrade() << " grade to execute." << std::endl;
	return (o);
}
