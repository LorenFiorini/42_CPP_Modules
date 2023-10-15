/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:29:43 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/15 03:16:19 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	createZombieOnStack(void)
{
	std::string	name;

	std::cout << "\nZombie on STACK" << std::endl;
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	
	randomChump(name);
}

static void	createZombieOnHeap(void)
{
	std::string	name;

	std::cout << "\nZombie on HEAP" << std::endl;
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	
	Zombie	*zombie_on_heap = newZombie(name);
	zombie_on_heap->announce();
	delete zombie_on_heap;
}

int	main(void)
{
	std::cout << "\nWelcome to BraiiiiiiinnnzzzZ!" << std::endl;
	std::cout << "This program creates two Zombies" << std::endl;
	std::cout << "One on the stack and another one on the heap." << std::endl;
	
	createZombieOnStack();
	createZombieOnHeap();
	return (0);
}
