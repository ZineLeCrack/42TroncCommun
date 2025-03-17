/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:04:35 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 16:49:24 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("undefinied")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	this->_signed = src._signed;
	return (*this);
}

const char *RobotomyRequestForm::IsNotSignedException::what() const throw()
{
	return ("The form is not signed !!!");
}

const std::string RobotomyRequestForm::getTarget()const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	std::srand(std::time(0));
	int rd = std::rand() % 2;

	if (this->getIsSignedBool() == false)
		throw IsNotSignedException();
	else if (executor.getGrade() > this->_grade_to_execute)
		throw GradeTooLowException();
	else if (rd == 0)
		std::cout << "The robotomy failed !" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized !" << std::endl;
}
