/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:01:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 23:15:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	*clapTrap = new ClapTrap("Clap Trap");
	ClapTrap	*clapTrap2 = new ClapTrap(*clapTrap);
	ScavTrap	*scavTrap = new ScavTrap("Scav Trap");
	ScavTrap	*scavTrap2 = new ScavTrap(*scavTrap);
	FragTrap	*fragTrap = new FragTrap("Frag Trap");
	FragTrap	*fragTrap2 = new FragTrap(*fragTrap);

	
	clapTrap2->setName("Trap Clap");
	scavTrap2->setName("Trap Scav");
	fragTrap2->setName("Trap Frag");

	std::cout << std::endl;
	clapTrap->attack(clapTrap2->getName());
	clapTrap2->takeDamage(clapTrap->getAttackDamage());
	
	std::cout << std::endl;
	scavTrap->attack(scavTrap2->getName());
	scavTrap2->takeDamage(scavTrap->getAttackDamage());
	scavTrap->guardGate();
	
	std::cout << std::endl;
	fragTrap->attack(fragTrap2->getName());
	fragTrap2->takeDamage(fragTrap->getAttackDamage());
	fragTrap->highFivesGuys();

	std::cout << std::endl;
	delete clapTrap;
	delete clapTrap2;
	delete scavTrap;
	delete scavTrap2;
	delete fragTrap;
	delete fragTrap2;
	return (0);
}
