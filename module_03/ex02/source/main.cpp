/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:01:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 06:52:25 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	*fragTrap = new FragTrap("FragTrap");
	FragTrap	*fragTrap2 = new FragTrap(*fragTrap);
	FragTrap	*fragTrap3 = new FragTrap("FragTrap3");
	
	fragTrap->attack("FragTrap2");
	fragTrap->takeDamage(5);
	fragTrap->attack("FragTrap2");
	fragTrap->beRepaired(5);
	fragTrap->attack("FragTrap2");
	fragTrap->takeDamage(100);
	fragTrap->attack("FragTrap2");
	fragTrap->beRepaired(100);
	fragTrap->attack("FragTrap2");
	fragTrap->highFivesGuys();
	
	delete fragTrap;
	delete fragTrap2;
	delete fragTrap3;
	return (0);
}
