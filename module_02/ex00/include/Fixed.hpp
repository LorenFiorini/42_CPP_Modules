/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:12:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 06:22:56 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);							// Default constructor
		Fixed(const Fixed &src);				// Copy constructor
		Fixed&	operator=(const Fixed &right);	// Copy assignment operator
		~Fixed();								// Destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
