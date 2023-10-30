/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:21:53 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:07:00 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    std::cout << "MateriaSource - default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
    std::cout << "MateriaSource - copy constructor" << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource(void) {
    std::cout << "MateriaSource - destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materia[i])
            delete this->_materia[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const &right) {
    std::cout << "MateriaSource - assignment operator" << std::endl;
    if (this != &right) {
        for (int i = 0; i < 4; i++)
            if (this->_materia[i])
                delete this->_materia[i];
        for (int i = 0; i < 4; i++)
            if (right._materia[i])
                this->_materia[i] = right._materia[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
    int i = 0;

    while (i < 4 && this->_materia[i])
        i++;
    if (i < 4)
        this->_materia[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    int i = 0;

    while (i < 4 && this->_materia[i] && this->_materia[i]->getType() != type)
        i++;
    if (i < 4 && this->_materia[i])
        return (this->_materia[i]->clone());
    return (NULL);
}
