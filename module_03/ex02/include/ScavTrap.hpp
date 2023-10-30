/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:04:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 22:58:26 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		ScavTrap(void);									// Default constructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);					// Copy constructor
		ScavTrap&	operator=(const ScavTrap &right);	// Copy assignment operator
		~ScavTrap(void);								// Destructor

		// Member function required by the subject
		void		guardGate(void);
		// Overriden member function
		void		attack(std::string const & target);
};

std::ostream&	operator<<(std::ostream& os, const ScavTrap& right);

#endif
