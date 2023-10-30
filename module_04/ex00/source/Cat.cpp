/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:27:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:53:15 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << " -> Cat: default constructor" << std::endl;
}

Cat	&Cat::operator=(const Cat &right)
{
	std::cout << " -> Cat: assignation operator" << std::endl;
	if (this != &right)
		this->_type = right.getType();
	return (*this);
}

Cat::Cat(const Cat &src)
{
	std::cout << " -> Cat: copy constructor" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << " -> Cat: destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << " -> Cat: \"Miau Miau\"" << std::endl;
}
