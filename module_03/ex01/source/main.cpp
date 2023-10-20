/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:01:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 06:42:32 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	*clapTrap = new ClapTrap("ClapTrap");
	ClapTrap	*clapTrap2 = new ClapTrap(*clapTrap);
	ClapTrap	*clapTrap3 = new ClapTrap("ClapTrap3");

	clapTrap->attack("ClapTrap2");
	clapTrap->takeDamage(5);
	clapTrap->attack("ClapTrap2");
	clapTrap->beRepaired(5);
	clapTrap->attack("ClapTrap2");
	clapTrap->takeDamage(100);
	clapTrap->attack("ClapTrap2");
	clapTrap->beRepaired(100);
	clapTrap->attack("ClapTrap2");

	delete clapTrap;
	delete clapTrap2;
	delete clapTrap3;
	return (0);
}
