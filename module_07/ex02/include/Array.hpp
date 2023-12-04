/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:50:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/04 19:02:05 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array {
		T				*_array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		Array	&operator=(Array const &rhs);
		~Array();

		//operator overload
		T		&operator[](unsigned int i);
		T		&operator[](unsigned int i) const;

		//getters
		unsigned int	getSize() const;
		T				*getAddress() const;

		class IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &rhs);

#include "../src/Array.tpp"
