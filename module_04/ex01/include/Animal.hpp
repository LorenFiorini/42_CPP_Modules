/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:38:02 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:22:27 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);							// Default constructor
		Animal(std::string type);				// Parameter constructor
		Animal	&operator=(const Animal &copy);	// Assignation operator
		Animal(const Animal &src);				// Copy constructor
		virtual	~Animal();						// Virtual Destructor (to allow delete of derived class)

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
