/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:13:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:20:02 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);								// Default constructor
		Dog		&operator=(const Dog &right);	// Assignation operator
		Dog(const Dog &src);					// Copy constructor
		~Dog();									// Destructor

		void	makeSound(void) const;
};

#endif
