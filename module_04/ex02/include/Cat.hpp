/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:07:48 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:22:05 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);								// Default constructor
		Cat		&operator=(const Cat &right);	// Assignation operator
		Cat(const Cat &src);					// Copy constructor
		~Cat();									// Destructor

		void	makeSound(void) const;
};

#endif
