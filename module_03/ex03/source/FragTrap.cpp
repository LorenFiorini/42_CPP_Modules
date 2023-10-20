/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:44:12 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 06:49:20 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
	this->_hitPoints	= 100;
	this->_energyPoints	= 100;
	this->_attackDamage	= 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " copied" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &right)
{
	this->_name			= right._name;
	this->_hitPoints	= right._hitPoints;
	this->_energyPoints	= right._energyPoints;
	this->_attackDamage	= right._attackDamage;
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to high five" << std::endl;
}
