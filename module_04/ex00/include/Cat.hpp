/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:07:48 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:21:09 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);								// Default constructor
		Cat(const Cat &src);					// Copy constructor
		~Cat();									// Destructor
		Cat		&operator=(const Cat &right);	// Assignation operator

		void	makeSound(void) const;
};

#endif
