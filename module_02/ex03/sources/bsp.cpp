/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:02:45 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 09:06:48 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	triangle_area(Point const a, Point const b, Point const c)
{
	Fixed	zero(0);
	Fixed	x1 = b.getX() - a.getX();
	Fixed	y1 = b.getY() - a.getY();
	Fixed	x2 = c.getX() - a.getX();
	Fixed	y2 = c.getY() - a.getY();
	Fixed	area = (x1 * y2 - x2 * y1) / Fixed(2);
	if (area < zero)
		area = zero - area;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	zero(0);
	Fixed	area_abc = triangle_area(a, b, c);
	Fixed	area_abp = triangle_area(a, b, point);
	Fixed	area_bcp = triangle_area(b, c, point);
	Fixed	area_cap = triangle_area(c, a, point);
	if (Fixed::min(Fixed::min(area_abc, area_abp), Fixed::min(area_bcp, area_cap)) == zero)
		return (false);
	if (area_abc < (area_abp + area_bcp + area_cap))
		return (false);
	return (true);
}
