/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:29:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:31:31 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &right)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = right.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog makeSound called" << std::endl;
	std::cout << "Woof Woof" << std::endl;
}
