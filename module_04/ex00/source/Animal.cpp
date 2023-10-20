/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:24:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:27:28 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal parameter constructor called" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &right)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->_type = right.getType();
	return (*this);
}

std::string	Animal::getType(void) const
{
	std::cout << "Animal getType called" << std::endl;
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makeSound called" << std::endl;
}
