/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:12 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 08:31:10 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <cstdlib>
# include <limits>

/** To-do
 *  Implement a member function to add many numbers to your Span in one call.
 */

class Span
{
	private:
		unsigned int		_capacity;
		unsigned int		_size;
		std::vector<int>	_vector;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &op);
		~Span(void);

		/* Getters */
		unsigned int		getCapacity(void) const;
		unsigned int		getSize(void) const;
		std::vector<int>	getVector(void) const;
		
		/* Member functions */
		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);


		/* Exceptions */
		class FullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
