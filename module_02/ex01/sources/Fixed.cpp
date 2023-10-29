/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:42:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 09:30:24 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}


Fixed&	Fixed::operator=(const Fixed &right)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = right.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
