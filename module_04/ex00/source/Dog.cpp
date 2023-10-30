/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:29:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:53:26 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << " -> Dog: default constructor" << std::endl;
	this->_type = "Dog";
}

Dog	&Dog::operator=(const Dog &right)
{
	std::cout << " -> Dog: assignation operator" << std::endl;
	if (this != &right)
		this->_type = right.getType();
	return (*this);
}

Dog::Dog(const Dog &src)
{
	std::cout << " -> Dog: copy constructor" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << " -> Dog: destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << " -> Dog: \"Woof Woof\"" << std::endl;
}
