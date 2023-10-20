/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:44:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/20 06:49:09 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected:
		FragTrap();										// Default constructor

	public:
		FragTrap(std::string name);						// Constructor with name
		FragTrap(const FragTrap &src);					// Copy constructor
		~FragTrap();									// Destructor
		FragTrap&	operator=(const FragTrap &right);	// Copy assignment operator

		void		highFivesGuys(void);
};

#endif
