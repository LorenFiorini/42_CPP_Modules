/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:32:48 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 04:26:27 by lfiorini         ###   ########.fr       */
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
		Fixed();								// Default constructor
		Fixed(const Fixed &src);				// Copy constructor
		~Fixed();								// Destructor
		Fixed&	operator=(const Fixed &right);	// Copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
