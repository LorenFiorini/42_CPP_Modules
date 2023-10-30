/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:21:44 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:00:42 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default") {
    std::cout << "Character - default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
    std::cout << "Character - constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

Character::Character(Character const &src) {
    std::cout << "Character - copy constructor" << std::endl;
    *this = src;
}

Character::~Character(void) {
    std::cout << "Character - destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

Character& Character::operator=(Character const &right) {
    std::cout << "Character - assignment operator" << std::endl;
    if (this != &right) {
        this->_name = right._name;
        for (int i = 0; i < 4; i++)
            if (this->_materia[i])
                delete this->_materia[i];
        for (int i = 0; i < 4; i++)
            if (right._materia[i])
                this->_materia[i] = right._materia[i]->clone();
    }
    return (*this);
}

std::string const & Character::getName() const {
    return (this->_name);
}

void Character::equip(AMateria* materia) {
    int i = 0;

    while (i < 4 && this->_materia[i])
        i++;
    if (i < 4)
        this->_materia[i] = materia;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_materia[idx])
        this->_materia[idx]->use(target);
}
