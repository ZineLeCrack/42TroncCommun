/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:36:05 by rlebaill          #+#    #+#             */
/*   Updated: 2025/02/26 10:51:07 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &copy) {(void)copy;}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}
