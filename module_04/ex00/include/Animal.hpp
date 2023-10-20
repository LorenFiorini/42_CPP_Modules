/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:38:02 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:21:32 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);							// Default constructor
		Animal(std::string type);				// Parameter constructor
		Animal(const Animal &src);				// Copy constructor
		virtual	~Animal();						// Virtual Destructor (to allow delete of derived class)
		Animal	&operator=(const Animal &copy);	// Assignation operator

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
