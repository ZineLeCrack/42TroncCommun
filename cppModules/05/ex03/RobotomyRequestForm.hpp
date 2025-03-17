/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:04:56 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/24 18:11:37 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:

		const std::string _target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		class IsNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		const std::string getTarget()const;

		void	execute(Bureaucrat const & executor)const;
};
