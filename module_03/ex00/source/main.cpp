/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 17:55:38 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	// Constructors with name
	ClapTrap	*john	= new ClapTrap("John");
	ClapTrap	*paul	= new ClapTrap("Paul");
	std::cout << *john << std::endl;
	std::cout << *paul << std::endl;

	// Copy constructor
	std::cout << std::endl;
	ClapTrap	*johnCopy	= new ClapTrap(*john);
	std::cout << *johnCopy << std::endl;
	
	// Copy assignment operator
	std::cout << std::endl;
	*paul = *john;
	std::cout << *paul << std::endl;

	// Setters
	std::cout << std::endl;
	john->setName("John Lennon");
	john->setHitPoints(100);
	john->setEnergyPoints(90);
	john->setAttackDamage(30);
	std::cout << *john << std::endl;
	paul->setName("Paul McCartney");
	paul->setHitPoints(90);
	paul->setEnergyPoints(100);
	paul->setAttackDamage(30);
	std::cout << *paul << std::endl;

	// Member functions required by the subject
	std::cout << std::endl;
	john->attack(paul->getName());
	paul->takeDamage(john->getAttackDamage());
	paul->beRepaired(10);

	// Destructors
	std::cout << std::endl;
	delete john;
	delete paul;
	delete johnCopy;	
	return (0);
}
