/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:23:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 05:06:20 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		ClapTrap();										// Default constructor, Maybe Private?
	public:
		ClapTrap(std::string name);						// Constructor with name
		ClapTrap(const ClapTrap &src);					// Copy constructor
		~ClapTrap();									// Destructor
		ClapTrap&	operator=(const ClapTrap &right);	// Copy assignment operator
		
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
