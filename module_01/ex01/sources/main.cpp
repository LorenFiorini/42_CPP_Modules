/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:00:38 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 09:44:24 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name	= "Cool Zombie";
	int			n		= 5;
	
	std::cout << "\nWelcome to Moar brainz!\n" << std::endl;
	Zombie	*horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	std::cout << "\nGoodbye!" << std::endl;
	return (0);
}
