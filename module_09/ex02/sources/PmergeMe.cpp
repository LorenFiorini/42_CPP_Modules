/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 01:54:49 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Orthodox Canonical Form */

PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src) {
		this->_vec = src._vec;
		this->_vec_tmp = src._vec_tmp;
		this->_deq = src._deq;
		this->_deq_tmp = src._deq_tmp;
	}
	return (*this);
}


PmergeMe::~PmergeMe(void) { }



bool	PmergeMe::is_input_valid(int argc, char **argv, std::stringstream& stream) 
{
	int	num;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);
		
		if (!(input >> num))
			return false;
		else if (num < 0)
			return false;
		else if (i + 1 == argc)
			stream << num;
		else
			stream << num << " ";
	}
	return (true);
}

void	PmergeMe::v_pair_elements(std::stringstream& stream)
{
	int	num;
	while (stream >> num) {
		_vec_tmp.push_back(num);
		if (stream >> num)
			_vec.push_back(num);
	}
}

void	PmergeMe::d_pair_elements(std::stringstream& stream)
{
	int	num;
	while (stream >> num) {
		_deq_tmp.push_back(num);
		if (stream >> num)
			_deq.push_back(num);
	}
}

void	PmergeMe::v_sort_pairs(void)
{
	int	num;

	for (size_t i = 0; i < _vec.size(); i++) {
		if ( _vec[i] > _vec_tmp[i])	{
			num = _vec[i];
			_vec[i] = _vec_tmp[i];
			_vec_tmp[i] = num;
		}
	}
}

void	PmergeMe::d_sort_pairs(void)
{
	int	num;

	for (size_t i = 0; i < _deq.size(); i++) {
		if ( _deq[i] > _deq_tmp[i])	{
			num = _deq[i];
			_deq[i] = _deq_tmp[i];
			_deq_tmp[i] = num;
		}
	}
}

void	PmergeMe::v_sort_main_chain(void)
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	jt;

	jt = _vec_tmp.begin();
	it = _vec.begin();
	while (it + 1 != _vec.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(jt, jt + 1);
			std::iter_swap(it, it + 1);
            jt = _vec_tmp.begin();
			it = _vec.begin();
		} else {
			jt++;
			it++;
		}
	}
}

void	PmergeMe::d_sort_main_chain(void)
{
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	jt;

	jt = _deq_tmp.begin();
	it = _deq.begin();
	while (it + 1 != _deq.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(jt, jt + 1);
			std::iter_swap(it, it + 1);
            jt = _deq_tmp.begin();
			it = _deq.begin();
		} else {
			jt++;
			it++;
		}
	}
}

int			PmergeMe::v_binary_search(int target)
{
	int	left	= 0;
	int	right	= _vec.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (target > _vec[middle]) {
			left = middle + 1;
		} else if (target < _vec[middle]) {
			right = middle - 1;
		} else {
			return (middle);
			// left = middle;
			// break;
		}
	}
	// _vec.insert(_vec.begin() + left, num);
	return (left);
}

int			PmergeMe::d_binary_search(int target)
{
	int	left	= 0;
	int	right	= _deq.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (target > _deq[middle]) {
			left = middle + 1;
		} else if (target < _deq[middle]) {
			right = middle - 1;
		} else {
			return (middle);
			// left = middle;
			// break;
		}
	}
	// _deq.insert(_deq.begin() + left, num);
	return (left);
}

std::vector<int>	PmergeMe::get_jacobsthal_vector(void)
{
	std::vector<int>	jacob(2, 0);
	std::vector<int>	index(1, 1);
	int					sz;
	int					num;

	num = 0;
	sz = _vec_tmp.size();
	jacob[1] = 1;
	while (num < sz) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 3; k < jacob.size(); k++)
	{
		int dif = jacob[k] - jacob[k - 1];
		int	id = jacob[k];
		for (int j = dif; j > 0; j--) {
			index.push_back(id);
			id--;
		}
	}
	return (index);
}

std::deque<int>	PmergeMe::get_jacobsthal_deque(void)
{
	std::deque<int>	jacob(2, 0);
	std::deque<int>	index(1, 1);
	int					sz;
	int					num;

	num = 0;
	sz = _deq_tmp.size();
	jacob[1] = 1;
	while (num < sz) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 3; k < jacob.size(); k++)
	{
		int dif = jacob[k] - jacob[k - 1];
		int	id = jacob[k];
		for (int j = dif; j > 0; j--) {
			index.push_back(id);
			id--;
		}
	}
	return (index);
}

void	PmergeMe::v_merge(void)
{
	std::vector<int>	jacob;
	int					sz;

	sz = _vec_tmp.size();
	jacob = get_jacobsthal_vector();
	int p = v_binary_search(_vec_tmp[0]);
	_vec.insert(_vec.begin() + p, _vec_tmp[0]);
	for (size_t i = 0; i < jacob.size(); i++) {
		if (jacob[i] < sz) {
			int	num = _vec_tmp[jacob[i]];
			int pos = v_binary_search(num);
			_vec.insert(_vec.begin() + pos, num);
		} else {
			// break;
			continue;
		}
	}
}

void	PmergeMe::d_merge(void)
{
	std::deque<int>	jacob;
	int					sz;

	sz = _deq_tmp.size();
	jacob = get_jacobsthal_deque();
	int p = d_binary_search(_deq_tmp[0]);
	_deq.insert(_deq.begin() + p, _deq_tmp[0]);
	for (size_t i = 0; i < jacob.size(); i++) {
		if (jacob[i] < sz) {
			int	num = _deq_tmp[jacob[i]];
			int pos = d_binary_search(num);
			_deq.insert(_deq.begin() + pos, num);
		} else {
			// break;
			continue;
		}
	}
}

void 	PmergeMe::display_result(int argc, char **argv, double v_time, double d_time)
{
	std::vector<int>::iterator	it;
	int					num;
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);
		input >> num;
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "After : ";
	for (it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(8) << std::setfill('0');
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << v_time << std::endl;
	std::cout << "Time to process a range of " << _deq.size()<< " elements with std::deque  : " << d_time << std::endl;
}

bool	PmergeMe::is_vector_sorted(void)
{
	std::vector<int>::iterator pos;
	
	pos = std::adjacent_find(_vec.begin(), _vec.end(), std::greater<int>());
	if (pos == _vec.end()) {
		std::cout << "Vector container is sorted." << std::endl;
		return (true);
	}
	std::cout << "Vector container is NOT sorted." << std::endl;
	return (false);
}

bool	PmergeMe::is_deque_sorted(void)
{
	std::deque<int>::iterator pos;
	
	pos = std::adjacent_find(_deq.begin(), _deq.end(), std::greater<int>());
	if (pos == _deq.end()) {
		std::cout << "Deque container is sorted." << std::endl;
		return (true);
	}
	std::cout << "Deque container is NOT sorted." << std::endl;
	return (false);
}

void	PmergeMe::v_print(int id)
{
	std::vector<int>::iterator	it;

	if (id == A) {
		std::cout << "Main chain (vector): ";
		for (it = _vec.begin(); it != _vec.end(); it++)
			std::cout << *it << " ";
	} else if (id == B) {
		std::cout << "2nd chain (vector): ";
		for (it = _vec_tmp.begin(); it != _vec_tmp.end(); it++)
			std::cout << *it << " ";
	} else {
		throw std::runtime_error("invalid id");
	}
	std::cout << std::endl;
}

void	PmergeMe::d_print(int id)
{
	std::deque<int>::iterator	it;

	if (id == A) {
		std::cout << "Main chain (deque): ";
		for (it = _deq.begin(); it != _deq.end(); it++)
			std::cout << *it << " ";
	} else if (id == B) {
		std::cout << "2nd chain (deque): ";
		for (it = _deq_tmp.begin(); it != _deq_tmp.end(); it++)
			std::cout << *it << " ";
	} else {
		throw std::runtime_error("invalid id");
	}
	std::cout << std::endl;
}
