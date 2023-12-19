/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:06 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 08:28:16 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Orthodox Canonical Class Form */

Span::Span(void)
	: _capacity(0), _size(0), _vector(std::vector<int>()) { }

Span::Span(unsigned int n)
	: _capacity(n), _size(0), _vector(std::vector<int>()) { }

Span::Span(const Span &src)
	: _capacity(src._capacity), _size(src._size), _vector(src._vector) { }

Span &Span::operator=(const Span &op)
{
	if (this != &op) {
		this->_capacity = op._capacity;
		this->_size = op._size;
		this->_vector = op._vector;
	}
	return (*this);
}

Span::~Span(void) { }


/* Getters */

unsigned int		Span::getCapacity(void) const {
	return (this->_capacity);
}

unsigned int		Span::getSize(void) const {
	return (this->_size);
}

std::vector<int>	Span::getVector(void) const {
	return (this->_vector);
}


/* Member functions */

void				Span::addNumber(int n) {
	if (this->_size >= this->_capacity) {
		throw Span::FullException();
	}
	this->_vector.push_back(n);
	this->_size++;
}

unsigned int		Span::shortestSpan(void) {
	if (this->_size <= 1) {
		throw Span::NoSpanException();
	}
	std::vector<int>	tmp(this->_vector);
	std::sort(tmp.begin(), tmp.end());
	unsigned int		min = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 0; i < this->_size - 1; i++) {
		if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) < min) {
			min = tmp[i + 1] - tmp[i];
		}
	}
	return (min);
}

unsigned int		Span::longestSpan(void) {
	if (this->_size <= 1) {
		throw Span::NoSpanException();
	}
	std::vector<int>	tmp(this->_vector);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[this->_size - 1] - tmp[0]);
}


/* Exceptions */

const char *Span::FullException::what() const throw() {
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw() {
	return ("No span to find");
}
