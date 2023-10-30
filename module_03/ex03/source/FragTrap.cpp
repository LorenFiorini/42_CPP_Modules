/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:44:12 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 23:16:07 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @brief Constructors & Destructor 
 */

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name			= "UnnamedFragTrap";
	this->_hitPoints	= 100;
	this->_energyPoints	= 100;
	this->_attackDamage	= 30;
	std::cout << "  FragTrap - default constructor for : " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name			= name;
	this->_hitPoints	= 100;
	this->_energyPoints	= 100;
	this->_attackDamage	= 30;
	std::cout << "  FragTrap - constructor for : " << this->_name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &right)
{
	ClapTrap::operator=(right);
	std::cout << "  FragTrap - copy assignment operator for : " << this->_name << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "  FragTrap - copy constructor for : " << this->_name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "  FragTrap - destructor for : " << this->_name << std::endl;
}

/**
 * @brief Member functions required by the subject
 */

void	FragTrap::highFivesGuys(void)
{
	std::cout << "  FragTrap - " << this->_name << " wants to high five you!" << std::endl;
}

/**
 * @brief Operator overload
 */

std::ostream&	operator<<(std::ostream& os, const FragTrap& right)
{
	os << "  FragTrap - " << right.getName() << std::endl;
	os << "    Hit Points: " << right.getHitPoints() << std::endl;
	os << "    Energy Points: " << right.getEnergyPoints() << std::endl;
	os << "    Attack Damage: " << right.getAttackDamage() << std::endl;
	return (os);
}
