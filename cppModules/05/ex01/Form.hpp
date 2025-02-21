/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:01:54 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/21 13:37:26 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	public:

		Form();
		Form(const Form &copy);
		Form(const int grade_to_sign, const int garde_to_execute);
		Form(const std::string name, const int grade_to_sign, const int garde_to_execute);
		~Form();

		Form &operator=(const Form &src);

		const std::string getName(void)const;
		bool getIsSignedBool(void)const;
		const int getSignGrade(void)const;
		const int getExecGrade(void)const;

		void 	beSigned(Bureaucrat &bureaucrat);
		void	signForm();

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

std::ostream	&operator<<(std::ostream &o, Form *a);
