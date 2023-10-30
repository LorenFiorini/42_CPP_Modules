/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:21:50 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:01:58 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure - default constructor" << std::endl;
}

Cure::Cure(Cure const &src) {
    std::cout << "Cure - copy constructor" << std::endl;
    *this = src;
}

Cure::~Cure(void) {
    std::cout << "Cure - destructor" << std::endl;
}

Cure& Cure::operator=(Cure const &right) {
    std::cout << "Cure - assignment operator" << std::endl;
    if (this != &right)
        this->_type = right._type;
    return (*this);
}

AMateria* Cure::clone() const {
    return (new Cure());
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
