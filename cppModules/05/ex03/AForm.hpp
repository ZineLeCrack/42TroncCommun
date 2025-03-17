/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:51:42 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 16:05:39 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
class Bureaucrat;

class AForm
{
	protected:

		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

		AForm();
		AForm(const AForm &copy);
		AForm(const int grade_to_sign, const int garde_to_execute);
		AForm(const std::string name, const int grade_to_sign, const int garde_to_execute);

	public:

		virtual ~AForm();

		AForm &operator=(const AForm &src);

		const std::string getName(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

		void 	beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor)const;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);
