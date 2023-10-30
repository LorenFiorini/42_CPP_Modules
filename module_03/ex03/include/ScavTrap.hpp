/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 05:04:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 00:11:21 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap&	operator=(const ScavTrap &right);
		~ScavTrap(void);

		void		guardGate(void);
		void		attack(std::string const & target);
};

std::ostream&	operator<<(std::ostream& os, const ScavTrap& right);

#endif
