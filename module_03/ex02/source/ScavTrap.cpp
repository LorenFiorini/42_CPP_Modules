/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:05:19 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 23:17:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @brief Constructors & Destructor 
 */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name			= "UnnamedScavTrap";
	this->_hitPoints	= 100;
	this->_energyPoints	= 50;
	this->_attackDamage	= 20;
	std::cout << "  ScavTrap - default constructor for : " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name			= name;
	this->_hitPoints	= 100;
	this->_energyPoints	= 50;
	this->_attackDamage	= 20;
	std::cout << "  ScavTrap - constructor for : " << this->_name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &right)
{
	ClapTrap::operator=(right);
	std::cout << "  ScavTrap - copy assignment operator for : " << this->_name << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "  ScavTrap - copy constructor for : " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "  ScavTrap - destructor for : " << this->_name << std::endl;
}

/**
 * @brief Member functions required by the subject
 */

void	ScavTrap::guardGate(void)
{
	std::cout << "  ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}

/**
 * @brief Overriden member function
 */

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints < 1) {
		std::cout << "  ScavTrap " << this->_name << " has not enough energy points to attack " << target << std::endl;
	} else if (this->_hitPoints < 1) {
		std::cout << "  ScavTrap " << this->_name << " is dead and can't attack " << target << std::endl;
	} else {
		std::cout << "  ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints	-= 1;
	}
}

/**
 * @brief Operator overload
 */

std::ostream&	operator<<(std::ostream& os, const ScavTrap& right)
{
	os << "\nScavTrap {" << std::endl;
	os << "  \"name\": \"" << right.getName() << "\"," << std::endl;
	os << "  \"hitPoints\": " << right.getHitPoints() << "," << std::endl;
	os << "  \"energyPoints\": " << right.getEnergyPoints() << "," << std::endl;
	os << "  \"attackDamage\": " << right.getAttackDamage() << std::endl;
	os << "}";
	return (os);
}
