/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:13:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:21:21 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);								// Default constructor
		Dog(const Dog &src);					// Copy constructor
		~Dog();									// Destructor
		Dog		&operator=(const Dog &right);	// Assignation operator

		void	makeSound(void) const;
};

#endif
