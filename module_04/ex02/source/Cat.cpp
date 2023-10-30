/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:27:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:59:53 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << " -> Cat: default constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_brain->setIdea(i, "Cat idea");
	}
}

Cat	&Cat::operator=(const Cat &right)
{
	std::cout << " -> Cat: assignation operator" << std::endl;
	if (this != &right) {
		this->_type = right._type;
		this->_brain = new Brain(*right._brain);
	}
	return (*this);
}

Cat::Cat(const Cat &src)
{
	std::cout << " -> Cat: copy constructor" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << " -> Cat: destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << " -> Cat: \"Miau Miau\"" << std::endl;
}
