/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:24:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:22:52 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << "Animal - default constructor" << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal - parameter constructor -> " << std::endl;
}

Animal	&Animal::operator=(const Animal &right)
{
	std::cout << "Animal - assignation operator" << std::endl;
	if (this != &right)
		this->_type = right.getType();
	return (*this);
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal - copy constructor -> " << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal - destructor" << std::endl;
}


std::string	Animal::getType(void) const
{
	std::cout << "Animal - getType" << std::endl;
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal - makeSound" << std::endl;
}
