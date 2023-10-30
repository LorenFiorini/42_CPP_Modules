/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:44:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 00:11:37 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		// Orthodox Canonical Class Form
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap&	operator=(const FragTrap &right);
		~FragTrap(void);

		void		highFivesGuys(void);
};

std::ostream&	operator<<(std::ostream& os, const FragTrap& right);

#endif
