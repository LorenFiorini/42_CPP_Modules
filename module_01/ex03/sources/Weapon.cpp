/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:25:29 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 09:44:24 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string   &Weapon::getType(void)
{
    return (this->_type);
}
