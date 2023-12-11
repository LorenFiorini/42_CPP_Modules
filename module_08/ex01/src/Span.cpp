/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:06 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:59:03 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Orthodox Canonical Class Form */

Span::Span(void) : _size(0) { }

Span::Span(unsigned int size) : _size(size) { }


Span::Span(const Span &src) : _container(std::vector<int>(src._container)), _size(src._size) { }

Span &Span::operator=(const Span &op)
{
	if (this != &op)
	{
		this->_size = op._size;
		this->_container = std::vector<int>(op._container);
	}
	return (*this);
}

Span::~Span(void) { }


/* Member Functions */

void	Span::addNumber(int n)
{
	if (_container.size() < _size)
		_container.push_back(n);
	else
		throw std::logic_error("the container is already full");
}

void	Span::fillContainerRandom(void)
{
	unsigned int currSize = _container.size();
	if (currSize == _size || _size == 0)
		return ;

	std::vector<int> tmp(_size - currSize);
	std::vector<int>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); it++)
		*it = rand() % 1000000;
	_container.insert(_container.end(), tmp.begin(), it);
}

void	Span::checkException(void)
{
	if (_container.size() == 0 || _container.size() == 1)
		throw std::logic_error("Container size too small.");
}

unsigned int	Span::shortestSpan(void)
{
	checkException();
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	int prev;

	std::sort(_container.begin(), _container.end());
	std::vector<int>::iterator it;

	for (it = _container.begin(); it != _container.end()--;)
	{
		prev = *it;
		unsigned int tmp = static_cast<unsigned int>(*(++it) - prev);
		shortest = std::min(shortest, tmp);
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void)
{
	checkException();

	int	minElement = *std::min_element(_container.begin(), _container.end());
    int	maxElement = *std::max_element(_container.begin(), _container.end());
	return (maxElement - minElement);
}

void	Span::printContainer(void)
{
	std::cout << "List of integers: " << std::endl;
	std::vector<int>::iterator it;

	for (it = _container.begin(); it != _container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
