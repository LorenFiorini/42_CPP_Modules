/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:58:13 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 08:03:23 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);							// Default constructor		
		Point(const Point &src);				// Copy constructor
		Point(const float x, const float y);	// Two Float constructor
		Point&	operator=(const Point &right);	// Copy assignment operator
		~Point();								// Destructor
		
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream&	operator<<(std::ostream &out, const Point &value);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif
