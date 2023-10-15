/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:00:38 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/15 03:38:46 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\nWelcome to Moar brainz!\n" << std::endl;

	Zombie	*horde = zombieHorde(5, "Cool Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
	std::cout << "\nGoodbye!" << std::endl;
	// system("leaks a.out");
	return (0);
}

/** 
 * @brief Subject
 * Time to create a horde of Zombies!
 * Implement the following function in the appropriate file:
 * 		Zombie* zombieHorde( int N, std::string name );
 * 
 * It must allocate N Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.
 * Implement your own tests to ensure your zombieHorde() function works as expected. Try to call announce() for each one of the zombies.
 * 
 * Don’t forget to delete all the zombies and check for memory leaks.
 *
 */