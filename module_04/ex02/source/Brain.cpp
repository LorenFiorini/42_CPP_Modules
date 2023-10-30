/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 04:18:56 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:32:44 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "---> {Brain} default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = "";
    }
}

Brain	&Brain::operator=(const Brain &right)
{
    std::cout << "---> {Brain} assignation operator called" << std::endl;
    if (this != &right) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = right._ideas[i];
        }
    }
    return (*this);
}

Brain::Brain(const Brain &src)
{
    std::cout << "---> {Brain} copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain()
{
    std::cout << "---> {Brain} destructor called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index > 99)
        return ;
    this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
    if (index < 0 || index > 99)
        return ("");
    return (this->_ideas[index]);
}
