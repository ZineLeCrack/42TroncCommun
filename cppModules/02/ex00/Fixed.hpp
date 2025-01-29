/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:09 by romain            #+#    #+#             */
/*   Updated: 2025/01/28 14:31:19 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

		int					_fp_value;
		static const int	_fract_bits;
	
	public:

		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed	&operator=(const Fixed &src);

		int		getRawBits()const;
		void	setRawBits(int const raw);
};

#endif
