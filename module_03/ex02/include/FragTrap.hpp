/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:44:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 23:05:56 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		FragTrap(void);									// Default constructor
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);					// Copy constructor
		FragTrap&	operator=(const FragTrap &right);	// Copy assignment operator
		~FragTrap(void);								// Destructor

		void		highFivesGuys(void);
};

std::ostream&	operator<<(std::ostream& os, const FragTrap& right);

#endif
