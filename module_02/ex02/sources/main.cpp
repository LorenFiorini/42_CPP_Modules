/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:49:14 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 07:13:07 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout	<< a	<< std::endl;
	std::cout	<< ++a	<< std::endl;
	std::cout	<< a	<< std::endl;
	std::cout	<< a++	<< std::endl;
	std::cout	<< a	<< std::endl;

	std::cout	<< b	<< std::endl;

	std::cout	<< Fixed::max( a, b ) << std::endl;

	return (0);
}
