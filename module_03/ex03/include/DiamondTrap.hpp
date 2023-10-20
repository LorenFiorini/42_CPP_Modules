/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:53:02 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 07:34:38 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include <iostream>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		_name;

	protected:
		DiamondTrap();											// Default constructor

	public:
		DiamondTrap(std::string name);							// Constructor with name
		DiamondTrap(const DiamondTrap &src);					// Copy constructor
		~DiamondTrap();											// Destructor
		DiamondTrap&	operator=(const DiamondTrap &right);	// Copy assignment operator
		
		void			attack(const std::string& target);
		void			whoAmI();
};

#endif
