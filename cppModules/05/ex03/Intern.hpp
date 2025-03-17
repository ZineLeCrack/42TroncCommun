/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:56:08 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/25 10:11:35 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Intern
{
	private:

	public:

		Intern();
		Intern(Intern const &copy);
		~Intern();

		Intern &operator=(Intern const &src);

		AForm *makeForm(std::string name, std::string target);

		class FormNameDoesNotExistException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
