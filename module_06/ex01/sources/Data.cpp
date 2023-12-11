/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:31:08 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:31:42 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _value(0) { }

Data::Data(Data const &src)
{
	*this = src;
}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
	}
	return (*this);
}

Data::~Data(void) { }

int Data::getValue(void) const
{
	return (this->_value);
}

void Data::setValue(int value)
{
	this->_value = value;
}
