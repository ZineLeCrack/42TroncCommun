/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:32:43 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:06:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib> //exit
# include <iostream> // cout getline
# include <string> //string compare length

class Contact
{
	private:
		std::string	_field_name[5];
		std::string _info[5];
		
	public:

	Contact();
	~Contact();

	void add_new();
	void get_infos(int index);
};

#endif
