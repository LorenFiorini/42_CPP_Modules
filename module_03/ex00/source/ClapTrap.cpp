/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:47 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 05:04:13 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name			= name;
	this->_hitPoints	= 10;
	this->_energyPoints	= 10;
	this->_attackDamage	= 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &right)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name			= right._name;
	this->_hitPoints	= right._hitPoints;
	this->_energyPoints	= right._energyPoints;
	this->_attackDamage	= right._attackDamage;
	return (*this);
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap\t" << this->_name << " can't attack because it has no energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap\t" << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints	-= 1;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage = amount;

	if (this->_hitPoints < damage) {
		damage = this->_hitPoints;
	}
	std::cout << "ClapTrap\t" << this->_name << " takes " << damage << " points of damage!" << std::endl;
	this->_hitPoints	-= damage;
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap\t" << this->_name << " is dead!" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap\t" << this->_name << " can't be repaired because it has no energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap\t" << this->_name << " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints	+= amount;
	this->_energyPoints	-= 1;
}
