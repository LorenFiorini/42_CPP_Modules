/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 05:04:33 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	*clap	= new ClapTrap("Clap");
	ClapTrap	*clap2	= new ClapTrap("Clap2");

	clap->attack("Clap2");
	clap2->takeDamage(5);
	clap2->beRepaired(5);
	delete clap;
	delete clap2;
	return (0);
}
