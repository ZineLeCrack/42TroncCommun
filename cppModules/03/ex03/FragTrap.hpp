/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:37:37 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 21:29:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:

	public:

		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void	attack(const std::string &target);
		void	highFiveGuys(void);
};

#endif
