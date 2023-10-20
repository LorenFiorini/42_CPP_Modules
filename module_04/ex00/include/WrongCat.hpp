/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:17:22 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:24:21 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);									// Default constructor
		WrongCat(const WrongCat &src);					// Copy constructor
		virtual		~WrongCat();						// Virtual Destructor (to allow delete of derived class)
		WrongCat	&operator=(const WrongCat &copy);	// Assignation operator

		void		makeSound(void) const;
};

#endif
