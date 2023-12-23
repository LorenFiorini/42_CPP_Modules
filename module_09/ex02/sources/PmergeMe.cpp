/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 23:14:00 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Orthodox Canonical Form */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _isVecSorted(false), _isDeqSorted(false)
{ }

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src) {
		this->_vec = src._vec;
		this->_vec_tmp = src._vec_tmp;
		this->_isVecSorted = src._isVecSorted;
		this->_deq = src._deq;
		this->_deq_tmp = src._deq_tmp;
		this->_isDeqSorted = src._isDeqSorted;
	}
	return (*this);
}


PmergeMe::~PmergeMe(void) { }



bool	PmergeMe::validateArguments(int argc, char **argv, std::stringstream& stream) 
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream	input(argv[i]);
		int number = 0;
		
		if (!(input >> number))
			return false;
		else if (number < 0)
			return false;
		else if (i + 1 == argc)
			stream << number;
		else
			stream << number << " ";
	}
	
	return true;
}

void	PmergeMe::v_pair_elements(std::stringstream& stream)
{
	int number = 0;
	
	while (stream >> number)
	{
		_vec_tmp.push_back(number);
		
		if (stream >> number)
		{
			_vec.push_back(number);
		}
	}
}

void	PmergeMe::d_pair_elements(std::stringstream& stream)
{
	int number = 0;
	
	while (stream >> number)
	{
		_deq_tmp.push_back(number);
		
		if (stream >> number)
		{
			_deq.push_back(number);
		}
	}
}

void	PmergeMe::v_sort_pairs(void)
{
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if ( _vec[i] > _vec_tmp[i])
		{
			int tmp = _vec[i];
			_vec[i] = _vec_tmp[i];
			_vec_tmp[i] = tmp;
		}
	}
}

void	PmergeMe::d_sort_pairs(void)
{
	for (size_t i = 0; i < _deq.size(); i++)
	{
		if ( _deq[i] > _deq_tmp[i])
		{
			int tmp = _deq[i];
			_deq[i] = _deq_tmp[i];
			_deq_tmp[i] = tmp;
		}
	}
}

void	PmergeMe::v_sort_main_chain(void)
{
	std::vector<int>::iterator	it = _vec.begin();
	std::vector<int>::iterator	jt = _vec_tmp.begin();
	
	while (it + 1 != _vec.end())
	{
		if (*it > *(it + 1))
		{
			std::iter_swap(it, it + 1);
			std::iter_swap(jt, jt + 1);
            it = _vec.begin();
            jt = _vec_tmp.begin();
		}
		else
		{
			it++;
			jt++;
		}
	}
}

void	PmergeMe::d_sort_main_chain(void)
{
	std::deque<int>::iterator	it = _deq.begin();
	std::deque<int>::iterator	jt = _deq_tmp.begin();
	
	while (it + 1 != _deq.end())
	{
		if (*it > *(it + 1))
		{
			std::iter_swap(it, it + 1);
			std::iter_swap(jt, jt + 1);
			it = _deq.begin();
            jt = _deq_tmp.begin();
		}
		else
		{
			it++;
			jt++;
		}
	}
}

void PmergeMe::v_binary_search(int number)
{
	int	left	= 0;
	int	right	= _vec.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (number > _vec[middle]) {
			left = middle + 1;
		} else if (number < _vec[middle]) {
			right = middle - 1;
		} else {
			_vec.insert(_vec.begin() + middle, number);
			return ;
		}
	}

	_vec.insert(_vec.begin() + left, number);
}

void PmergeMe::d_binary_search(int number)
{
	int	left	= 0;
	int	right	= _deq.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (number > _deq[middle]) {
			left = middle + 1;
		} else if (number < _deq[middle]) {
			right = middle - 1;
		} else {
			_deq.insert(_deq.begin() + middle, number);
			return ;
		}
	}

	_deq.insert(_deq.begin() + left, number);
}

std::vector<int>	PmergeMe::get_jacobsthal_vector(void)
{
	std::vector<int>	jacob;
	std::vector<int>	index;
	int	size = _vec_tmp.size();
	unsigned long k;
	int num = 0;
	int i = 0;

	jacob.push_back(0);
	jacob.push_back(1);
	while (num < size) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	index.push_back(1);
	for (k = 3; k < jacob.size(); k++)
	{
		i = jacob[k];
		num = jacob[k] - jacob[k - 1];
		for (int j = num; j > 0; j--)
			index.push_back(i--);
	}
	return index;
}

std::deque<int>	PmergeMe::get_jacobsthal_deque(void)
{
	std::deque<int>	jacob;
	std::deque<int>	index;
	int	size = _deq_tmp.size();
	unsigned long k;
	int num = 0;
	int i = 0;

	jacob.push_back(0);
	jacob.push_back(1);
	while (num < size) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	index.push_back(1);
	for (k = 3; k < jacob.size(); k++)
	{
		i = jacob[k];
		num = jacob[k] - jacob[k - 1];
		for (int j = num; j > 0; j--)
			index.push_back(i--);
	}
	return index;
}

void	PmergeMe::insertVec(void)
{
	std::vector<int>	jacob = get_jacobsthal_vector();
	int jacobSize = jacob.size();
	int pendSize = _vec_tmp.size() - 1;
	int index = 0;

	v_binary_search(_vec_tmp[0]);
	for (int i = 0; i < jacobSize; i++)
	{
		if (jacob[i] <= pendSize)
		{
			index = jacob[i];
			v_binary_search(_vec_tmp[index]);
		}
		else
			continue;
	}

}

void	PmergeMe::insertDeq(void)
{
	std::deque<int>	jacob = get_jacobsthal_deque();
	int jacobSize = jacob.size();
	int pendSize = _deq_tmp.size() - 1;
	int index = 0;

	d_binary_search(_deq_tmp[0]);
	for (int i = 0; i < jacobSize; i++)
	{
		if (jacob[i] <= pendSize)
		{
			index = jacob[i];
			d_binary_search(_deq_tmp[index]);
		}
		else
			continue;
	}

}

void 	PmergeMe::displayUnsortedSequence(int argc, char **argv)
{
	std::stringstream stream;

	for (int i = 1; i < argc; i++)
	{
		std::stringstream	input(argv[i]);
		int number = 0;
		
		input >> number;
		std::cout << number << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::displaySortedSequence(void)
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::displayTime(double vecTime, double decTime)
{
	std::cout << std::fixed << std::setprecision(8) << std::setfill('0');
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << std::endl;
	std::cout << "Time to process a range of " << _deq.size()<< " elements with std::deque  : " << decTime << std::endl;
}

void	PmergeMe::checkIfVecSorted(void)
{
	std::vector<int>::iterator pos;
	
	pos = std::adjacent_find(_vec.begin(), _vec.end(), std::greater<int>());
	if (pos == _vec.end())
		std::cout << "Vector container is sorted." << std::endl;
	else
    	std::cout << "Vector container is NOT sorted." << std::endl;
}

void	PmergeMe::checkIfDeqSorted(void)
{
	std::deque<int>::iterator pos;
	
	pos = std::adjacent_find(_deq.begin(), _deq.end(), std::greater<int>());
	if (pos == _deq.end())
    	std::cout << "Deque container is sorted." << std::endl;
	else
    	std::cout << "Deque container is NOT sorted." << std::endl;
}

void	PmergeMe::printVec(int id)
{
	if (id != A && id != B)
		throw std::runtime_error("invalid id");

	if (id == A)
	{
		std::cout << "main vec: ";
		
		for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "pend vec: ";
		
		for (std::vector<int>::iterator it = _vec_tmp.begin(); it != _vec_tmp.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::printDeq(int id)
{
	if (id != A && id != B)
		throw std::runtime_error("invalid id");

	if (id == A)
	{
		std::cout << "main deq: ";
		
		for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "pend deq: ";
		
		for (std::deque<int>::iterator it = _deq_tmp.begin(); it != _deq_tmp.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}
