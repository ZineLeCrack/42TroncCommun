/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:47:17 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 18:11:44 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:

		const std::string _target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

		class IsNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		const std::string getTarget()const;

		void	execute(Bureaucrat const & executor)const;
};