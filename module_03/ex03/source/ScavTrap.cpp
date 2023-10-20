/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:05:19 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 06:41:34 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->_name			= name;
	this->_hitPoints	= 100;
	this->_energyPoints	= 50;
	this->_attackDamage	= 20;
	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	*this = src;
	std::cout << "ScavTrap " << this->_name << " copied." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &right)
{
	this->_name			= right._name;
	this->_hitPoints	= right._hitPoints;
	this->_energyPoints	= right._energyPoints;
	this->_attackDamage	= right._attackDamage;
	return (*this);
}

void		ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void		ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << std::endl;
}
