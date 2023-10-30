/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:53:02 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 00:45:45 by lfiorini         ###   ########.fr       */
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
	public:
		// Constructors and Destructors
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap&	operator=(const DiamondTrap &right);
		~DiamondTrap(void);

		void			whoAmI(void);

		// Getters and Setters
		std::string		getName(void) const;
		void			setName(std::string name);

		// ScavTrap functions
		void			attack(std::string const & target);
};

#endif
