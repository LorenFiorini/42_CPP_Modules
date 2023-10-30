/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:36:11 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 03:55:48 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "-> [WrongCat] default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "-> [WrongCat] copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "-> [WrongCat] destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &right)
{
	std::cout << "-> [WrongCat] assignation operator called" << std::endl;
	this->_type = right.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "-> [WrongCat] makeSound called" << std::endl;
	std::cout << "Oink Oink" << std::endl;
}
