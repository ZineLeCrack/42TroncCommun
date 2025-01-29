/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:29:10 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 19:41:15 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory adress of str : " << &str << std::endl;
	std::cout << "Memory adress of stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory adress of stringREF : " << &stringREF << std::endl;

	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value of stringREF : " << stringREF << std::endl;

	return (0);
}
