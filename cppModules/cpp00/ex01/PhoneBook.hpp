/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:34:41 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 17:22:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _PhoneBook[8];
		int		_index;
		
	public:

	PhoneBook();
	~PhoneBook();

	void	add_contact();
	void	get_contact_infos();
};

#endif