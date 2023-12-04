/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:50:35 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/04 19:04:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> const &src) : _array(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < src._size; i++) {
		this->_array[i] = src._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->_size >= rhs._size)
		{
			for (unsigned int i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
			this->_size = rhs._size;
		}
		else
		{
			delete [] this->_array;
			this->_array = new T[rhs._size];
			this->_size = rhs._size;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw Array<T>::IndexOutOfRangeException();
	return (this->_array[i]);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw Array<T>::IndexOutOfRangeException();
	return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
	return (this->_size);
}

template <typename T>
T *Array<T>::getAddress() const
{
	return (this->_array);
}

template <typename T>
const char *Array<T>::IndexOutOfRangeException::what() const throw()
{
	return ("Index out of range.");
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &rhs)
{
	o << rhs.getAddress();
	return (o);
}
