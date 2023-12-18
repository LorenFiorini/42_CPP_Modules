/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:50:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 19:11:27 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		Array	&operator=(Array const &rhs);
		~Array(void);

		T		&operator[](unsigned int i);
		T		&operator[](unsigned int i) const;

		unsigned int	getSize() const;
		T				*getAddress() const;
		
		unsigned int	size() const;

		class IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &rhs);

#include "../sources/Array.tpp"

#endif
