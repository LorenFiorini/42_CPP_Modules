/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 22:58:08 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Orthodox Canonical Class Form 
		ClapTrap(void);									// Default constructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);					// Copy constructor
		ClapTrap&	operator=(const ClapTrap &right);	// Copy assignment operator
		~ClapTrap(void);								// Destructor
		
		// Getters
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		// Setters
		void			setName(std::string name);
		void			setHitPoints(unsigned int hitPoints);
		void			setEnergyPoints(unsigned int energyPoints);
		void			setAttackDamage(unsigned int attackDamage);

		// Member functions required by the subject
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

std::ostream&	operator<<(std::ostream& os, const ClapTrap& right);

#endif
