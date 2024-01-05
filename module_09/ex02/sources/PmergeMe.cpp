/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 03:09:31 by lfiorini         ###   ########.fr       */
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
		this->_vector = src._vector;
		this->_vec_tmp = src._vec_tmp;
		this->_deque = src._deque;
		this->_deq_tmp = src._deq_tmp;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) { }


void		PmergeMe::v_pair_elements(std::stringstream& stream)
{
	int	num;

	while (stream >> num) {
		_vec_tmp.push_back(num);
		if (stream >> num)
			_vector.push_back(num);
	}
}

void		PmergeMe::d_pair_elements(std::stringstream& stream)
{
	int	num;

	while (stream >> num) {
		_deq_tmp.push_back(num);
		if (stream >> num)
			_deque.push_back(num);
	}
}

void		PmergeMe::v_sort_pairs(void)
{
	int	num;

	for (size_t i = 0; i < _vector.size(); i++) {
		if ( _vector[i] > _vec_tmp[i])	{
			num = _vector[i];
			_vector[i] = _vec_tmp[i];
			_vec_tmp[i] = num;
		}
	}
}

void		PmergeMe::d_sort_pairs(void)
{
	int	num;

	for (size_t i = 0; i < _deque.size(); i++) {
		if ( _deque[i] > _deq_tmp[i])	{
			num = _deque[i];
			_deque[i] = _deq_tmp[i];
			_deq_tmp[i] = num;
		}
	}
}

void		PmergeMe::v_sort_main_chain(void)
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	jt;

	jt = _vec_tmp.begin();
	it = _vector.begin();
	while (it + 1 != _vector.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(jt, jt + 1);
			std::iter_swap(it, it + 1);
			jt = _vec_tmp.begin();
			it = _vector.begin();
		} else {
			jt++;
			it++;
		}
	}
}

void		PmergeMe::d_sort_main_chain(void)
{
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	jt;

	jt = _deq_tmp.begin();
	it = _deque.begin();
	while (it + 1 != _deque.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(jt, jt + 1);
			std::iter_swap(it, it + 1);
			jt = _deq_tmp.begin();
			it = _deque.begin();
		} else {
			jt++;
			it++;
		}
	}
}

int			PmergeMe::v_binary_search(int target)
{
	int	left	= 0;
	int	right	= _vector.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (target > _vector[middle]) {
			left = middle + 1;
		} else if (target < _vector[middle]) {
			right = middle - 1;
		} else {
			return (middle);
		}
	}
	return (left);
}

int			PmergeMe::d_binary_search(int target)
{
	int	left	= 0;
	int	right	= _deque.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2;
		if (target > _deque[middle]) {
			left = middle + 1;
		} else if (target < _deque[middle]) {
			right = middle - 1;
		} else {
			return (middle);
		}
	}
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
	int				sz;
	int				num;

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

void		PmergeMe::v_merge(void)
{
	std::vector<int>	jacob;
	int					num;
	int					pos;

	jacob = get_jacobsthal_vector();
	num = _vec_tmp[0];
	pos = v_binary_search(num);
	_vector.insert(_vector.begin() + pos, num);
	for (size_t i = 0; i < jacob.size(); i++) {
		if (jacob[i] < (int) _vec_tmp.size()) {
			num = _vec_tmp[jacob[i]];
			pos = v_binary_search(num);
			_vector.insert(_vector.begin() + pos, num);
		} else {
			// break;
			continue;
		}
	}
}

void		PmergeMe::d_merge(void)
{
	std::deque<int>	jacob;
	int				num;
	int				pos;

	jacob = get_jacobsthal_deque();
	num = _deq_tmp[0];
	pos = d_binary_search(num);
	_deque.insert(_deque.begin() + pos, num);
	for (size_t i = 0; i < jacob.size(); i++) {
		if (jacob[i] < (int) _deq_tmp.size()) {
			num = _deq_tmp[jacob[i]];
			pos = d_binary_search(num);
			_deque.insert(_deque.begin() + pos, num);
		} else {
			// break;
			continue;
		}
	}
}

bool	PmergeMe::is_vector_sorted(void)
{
	std::vector<int>::iterator pos;
	
	pos = std::adjacent_find(_vector.begin(), _vector.end(), std::greater<int>());
	if (pos == _vector.end()) {
		std::cout << "Vector container is sorted." << std::endl;
		return (true);
	}
	std::cout << "Vector container is NOT sorted." << std::endl;
	return (false);
}

bool	PmergeMe::is_deque_sorted(void)
{
	std::deque<int>::iterator pos;
	
	pos = std::adjacent_find(_deque.begin(), _deque.end(), std::greater<int>());
	if (pos == _deque.end()) {
		std::cout << "Deque container is sorted." << std::endl;
		return (true);
	}
	std::cout << "Deque container is NOT sorted." << std::endl;
	return (false);
}

void		PmergeMe::v_print(int id)
{
	std::vector<int>::iterator	it;

	if (id == A) {
		std::cout << "Main chain (vector): ";
		for (it = _vector.begin(); it != _vector.end(); it++)
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

void		PmergeMe::d_print(int id)
{
	std::deque<int>::iterator	it;

	if (id == A) {
		std::cout << "Main chain (deque): ";
		for (it = _deque.begin(); it != _deque.end(); it++)
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


double	PmergeMe::sort_using_vector(std::stringstream &stream)
{
	clock_t start = clock();
	
	this->v_pair_elements(stream);
	this->v_sort_pairs();
	this->v_sort_main_chain();
	this->v_merge();
	clock_t end = clock();
	
	double v_time = double(end - start) / double(CLOCKS_PER_SEC);
	
	return (v_time);
}

double	PmergeMe::sort_using_deque(std::stringstream &stream)
{
	clock_t start = clock();
	
	stream.clear();
	stream.seekg(0, std::ios::beg);
	this->d_pair_elements(stream);
	this->d_sort_pairs();
	this->d_sort_main_chain();
	this->d_merge();
	clock_t end = clock();
	
	double d_time = double(end - start) / double(CLOCKS_PER_SEC);
	
	return (d_time);
}

bool	PmergeMe::is_input_valid(int argc, char **argv, std::stringstream& stream) 
{
	int	num;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);

		if (!(input >> num)) {
			return false;
		} else if (num < 0) {
			return false;
		} else {
			if (i + 1 == argc) 
				stream << num;
			else
				stream << num << " ";
			this->_sequence.push_back(num);
		}
	}
	return (true);
}

void 	PmergeMe::display_result(double v_time, double d_time)
{
	std::vector<int>::iterator	it;

	std::cout << "Before: ";
	for (it = _sequence.begin(); it != _sequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "After : ";
	for (it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::fixed << std::setprecision(8) << std::setfill('0');
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << v_time << std::endl;
	std::cout << "Time to process a range of " << _deque.size()<< " elements with std::deque  : " << d_time << std::endl;
}
