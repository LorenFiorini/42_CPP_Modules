/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:58:24 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 08:02:14 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point&	Point::operator=(const Point &right)
{
	(Fixed) this->_x = right._x;
	(Fixed) this->_y = right._y;
	return (*this);
}

Point::~Point()
{
}

std::ostream&	operator<<(std::ostream &out, const Point &value)
{
	out << "(" << value.getX() << ", " << value.getY() << ")";
	return (out);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
