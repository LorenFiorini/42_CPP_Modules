/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:22:12 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:02:57 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice - default constructor" << std::endl;
}

Ice::Ice(Ice const &src) {
    std::cout << "Ice - copy constructor" << std::endl;
    *this = src;
}

Ice::~Ice(void) {
    std::cout << "Ice - destructor" << std::endl;
}

Ice& Ice::operator=(Ice const &right) {
    std::cout << "Ice - assignment operator" << std::endl;
    if (this != &right)
        this->_type = right._type;
    return (*this);
}

AMateria* Ice::clone() const {
    return (new Ice());
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
