/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:40:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:05 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) : _raw(0)

Serializer::Serializer(Serializer const &src)
{
	(void)src;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return (*this);
}

Serializer::~Serializer(void) { }


uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
