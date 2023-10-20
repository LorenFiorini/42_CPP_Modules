/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:04:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 05:15:48 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();										// Default constructor

	public:
		ScavTrap(std::string name);						// Constructor with name
		ScavTrap(const ScavTrap &src);					// Copy constructor
		~ScavTrap();									// Destructor
		ScavTrap&	operator=(const ScavTrap &right);	// Copy assignment operator

		void		attack(const std::string& target);
		void		guardGate();
};

#endif
