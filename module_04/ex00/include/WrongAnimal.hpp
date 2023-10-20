/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:14:19 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/21 00:23:43 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);									// Default constructor
		WrongAnimal(const WrongAnimal &src);				// Copy constructor
		virtual		~WrongAnimal();							// Virtual Destructor (to allow delete of derived class)
		WrongAnimal	&operator=(const WrongAnimal &copy);	// Assignation operator

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
