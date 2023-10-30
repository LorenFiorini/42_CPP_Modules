/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:47 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 23:16:36 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Constructors & Destructor 
 */

ClapTrap::ClapTrap(void)
{
	this->_name			= "UnnamedClapTrap";
	this->_hitPoints	= 10;
	this->_energyPoints	= 10;
	this->_attackDamage	= 0;
	std::cout << "ClapTrap - default constructor for : " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name			= name;
	this->_hitPoints	= 10;
	this->_energyPoints	= 10;
	this->_attackDamage	= 0;
	std::cout << "ClapTrap - constructor for : " << this->_name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &right)
{
	if (this != &right) {
		this->_name			= right._name;
		this->_hitPoints	= right._hitPoints;
		this->_energyPoints	= right._energyPoints;
		this->_attackDamage	= right._attackDamage;
	}
	std::cout << "ClapTrap - copy assignment operator for : " << this->_name << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap - copy constructor for : " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap - destructor for : " << this->_name << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const ClapTrap& right)
{
	os << "\nClapTrap {" << std::endl;
	os << "  \"name\": \"" << right.getName() << "\"," << std::endl;
	os << "  \"hitPoints\": " << right.getHitPoints() << "," << std::endl;
	os << "  \"energyPoints\": " << right.getEnergyPoints() << "," << std::endl;
	os << "  \"attackDamage\": " << right.getAttackDamage() << std::endl;
	os << "}";
	return (os);
}

/**
 * @brief Getters for private attributes
 */

std::string		ClapTrap::getName(void) const 
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}



/**
 * @brief Setters for private attributes
 */

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void		ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void		ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void		ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}



/**
 * @brief Member functions required by the subject
 */

void		ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack because it has no energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints	-= 1;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage = amount;

	if (this->_hitPoints < damage) {
		damage = this->_hitPoints;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << damage << " points of damage!" << std::endl;
	this->_hitPoints	-= damage;
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " can't be repaired because it has no energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints	+= amount;
	this->_energyPoints	-= 1;
}
