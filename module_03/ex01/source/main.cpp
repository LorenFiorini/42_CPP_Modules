/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:01:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 22:33:43 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	*A = new ClapTrap("A");
	ScavTrap	*B = new ScavTrap("B");
	
	std::cout << *A << std::endl;	
	std::cout << *B << std::endl;
	
	A->attack(B->getName());
	B->takeDamage(A->getAttackDamage());
	B->beRepaired(10);

	std::cout << *A << std::endl;
	std::cout << *B << std::endl;
	
	B->guardGate();
	B->attack(A->getName());
	A->takeDamage(B->getAttackDamage());
	A->beRepaired(10);

	std::cout << *A << std::endl;
	std::cout << *B << std::endl;

	delete A;
	delete B;
	return (0);
}
