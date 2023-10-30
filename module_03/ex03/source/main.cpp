/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:01:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 00:54:58 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap     *john = new DiamondTrap("John");
    DiamondTrap     *jamie = new DiamondTrap("Jamie");
    
    john->attack(jamie->getName());
    jamie->takeDamage(john->getAttackDamage());
    jamie->beRepaired(10);

    delete john;
    delete jamie;
    return (0);    
}
