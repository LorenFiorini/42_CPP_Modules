/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:12 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:55:35 by lfiorini         ###   ########.fr       */
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

class Span
{

	private:
		std::vector<int>	_container;
		unsigned int		_size;

	public:
		Span(void);
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &op);
		~Span(void);

		void			addNumber(int n);
		void			fillContainerRandom(void);
		template <typename Itr>
		void			fillContainerRange(Itr first, Itr last);
		void			checkException(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			printContainer(void);

};

template <typename Itr>
void	Span::fillContainerRange(Itr first, Itr last)
{
	if (std::distance(first, last) + _container.size() > _size)
		throw std::logic_error("no efficient place to insert integers");
	_container.insert(_container.end(), first, last);
}

#endif
