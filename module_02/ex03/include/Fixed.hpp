/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:14:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 07:45:49 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);							// Default constructor
		Fixed(const int value);					// Int constructor
		Fixed(const float value);				// Float constructor
		Fixed(const Fixed &src);				// Copy constructor
		Fixed&	operator=(const Fixed &right);	// Copy assignment operator
		~Fixed();								// Destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &right) const;
		bool	operator<(const Fixed &right) const;
		bool	operator>=(const Fixed &right) const;
		bool	operator<=(const Fixed &right) const;
		bool	operator==(const Fixed &right) const;
		bool	operator!=(const Fixed &right) const;
		
		Fixed	operator+(const Fixed &right) const;
		Fixed	operator-(const Fixed &right) const;
		Fixed	operator*(const Fixed &right) const;
		Fixed	operator/(const Fixed &right) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&	min(Fixed &a, Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &value);

#endif
