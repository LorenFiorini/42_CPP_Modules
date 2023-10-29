/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:49:17 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 07:46:14 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{

}

Fixed&	Fixed::operator=(const Fixed &right)
{
	this->_value = right.getRawBits();
	return (*this);
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

/*		Comparison Operators		*/

bool	Fixed::operator>(const Fixed &right) const
{
	return (this->_value > right.getRawBits());
}

bool	Fixed::operator<(const Fixed &right) const
{
	return (this->_value < right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right) const
{
	return (this->_value >= right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right) const
{
	return (this->_value <= right.getRawBits());
}

bool	Fixed::operator==(const Fixed &right) const
{
	return (this->_value == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right) const
{
	return (this->_value != right.getRawBits());
}

/*		Arithmetic Operators		*/

Fixed	Fixed::operator+(const Fixed &right) const
{
	return (Fixed(this->toFloat() + right.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &right) const
{
	return (Fixed(this->toFloat() - right.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &right) const
{
	return (Fixed(this->toFloat() * right.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &right) const
{
	return (Fixed(this->toFloat() / right.toFloat()));
}

/*		Increment & Decrement Operators		*/

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_value--;
	return (tmp);
}

/*		Min & Max Functions		*/

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
