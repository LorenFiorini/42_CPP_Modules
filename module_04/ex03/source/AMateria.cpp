/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:21:47 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:05:28 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {
    std::cout << "AMateria - default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
    std::cout << "AMateria - constructor" << std::endl;
}

AMateria::AMateria(AMateria const &src) {
    std::cout << "AMateria - copy constructor" << std::endl;
    *this = src;
}

AMateria::~AMateria(void) {
    std::cout << "AMateria - destructor" << std::endl;
}

AMateria& AMateria::operator=(AMateria const &right) {
    std::cout << "AMateria - assignment operator" << std::endl;
    if (this != &right)
        this->_type = right._type;
    return (*this);
}

std::string const & AMateria::getType() const {
    return (this->_type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria virtual function. It's not possible to USE " << this->_type << " on " << target.getName() << std::endl;
}
