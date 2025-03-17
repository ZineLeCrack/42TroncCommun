/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:59:14 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 18:11:24 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:

		const std::string _target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		class IsNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		const std::string getTarget()const;

		void	execute(Bureaucrat const & executor)const;
};
