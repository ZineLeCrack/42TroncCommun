/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:04:35 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 16:49:24 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("undefinied")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm(copy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->_signed = src._signed;
	return (*this);
}

const char *PresidentialPardonForm::IsNotSignedException::what() const throw()
{
	return ("The form is not signed !!!");
}

const std::string PresidentialPardonForm::getTarget()const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	std::ofstream	outfile;

	if (this->getIsSignedBool() == false)
		throw IsNotSignedException();
	else if (executor.getGrade() > this->_grade_to_execute)
		throw GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !"
		<< std::endl;
}
