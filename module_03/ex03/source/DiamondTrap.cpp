/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:55:01 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 00:54:56 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors and Destructors

DiamondTrap::DiamondTrap(void) : ClapTrap("Unknown_clap_name"), ScavTrap("Unknown"), FragTrap("Unknown"), _name("Unknown")
{
	this->_hitPoints	= FragTrap::_hitPoints;
	this->_energyPoints	= ScavTrap::_energyPoints;
	this->_attackDamage	= FragTrap::_attackDamage;
	std::cout << " < DiamondTrap > default constructor called -> " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints	= FragTrap::_hitPoints;
	this->_energyPoints	= ScavTrap::_energyPoints;
	this->_attackDamage	= FragTrap::_attackDamage;
	std::cout << " < DiamondTrap > constructor called -> " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name			= src.getName();
	std::cout << " < DiamondTrap > copy constructor called -> " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << " < DiamondTrap > destructor called -> " << this->_name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &right)
{
	if (this == &right)
		return (*this);
	ScavTrap::operator=(right);
	FragTrap::operator=(right);
	this->_name	= right._name;
	std::cout << " < DiamondTrap > assignation operator called -> " << this->_name << std::endl;
	return (*this);
}


// Getters and Setters

std::string		DiamondTrap::getName(void) const
{
	return (this->_name);
}

void			DiamondTrap::setName(std::string name)
{
	this->_name = name;
}


void			DiamondTrap::whoAmI(void)
{
	std::cout << " < DiamondTrap > My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void			DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
