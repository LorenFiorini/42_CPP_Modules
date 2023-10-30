/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 04:06:55 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:52:49 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);							// Default constructor
		Brain	&operator=(const Brain &right);	// Assignation operator
		Brain(const Brain &src);				// Copy constructor
		~Brain();								// Destructor

		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};


#endif
