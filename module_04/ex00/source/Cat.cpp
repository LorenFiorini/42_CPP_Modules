/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:27:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:31:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &right)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->_type = right.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat makeSound called" << std::endl;
	std::cout << "Miau Miau" << std::endl;
}
