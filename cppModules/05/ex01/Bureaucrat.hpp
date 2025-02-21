/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:16:26 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/21 12:36:42 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

		void		setGrade(int garde);

	public:

		Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat(const std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &src);

		const std::string	getName()const;
		int					getGrade()const;

		void		incrementGrade();
		void		decrementGrade();

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
