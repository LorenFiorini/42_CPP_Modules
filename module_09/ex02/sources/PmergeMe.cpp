/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 11:04:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Orthodox Canonical Form */

PmergeMe::PmergeMe(void) { }

PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
	if (this == &src) {
		this->_vecL = src._vecL;
		this->_deqL = src._deqL;
		this->_vecR = src._vecR;
		this->_deqR = src._deqR;
	}
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void) { }


/* Member Functions */


void	PmergeMe::v_pair_elements(std::stringstream& stream)
{
	int	num;

	while (stream >> num) {
		_vecR.push_back(num);
		if (stream >> num) {
			_vecL.push_back(num);
		}
	}
}

void	PmergeMe::d_pair_elements(std::stringstream& stream)
{
	int	num;

	while (stream >> num) {
		_deqR.push_back(num);
		if (stream >> num) {
			_deqL.push_back(num);
		}
	}
}

void	PmergeMe::v_sort_pairs(void)
{
	for (size_t i = 0; i < _vecL.size(); i++) {
		if (_vecL[i] > _vecR[i]) {
			int tmp = _vecL[i];
			_vecL[i] = _vecR[i];
			_vecR[i] = tmp;
		}
	}
}

void	PmergeMe::d_sort_pairs(void)
{
	for (size_t i = 0; i < _deqL.size(); i++) {
		if (_deqL[i] > _deqR[i]) {
			int tmp = _deqL[i];
			_deqL[i] = _deqR[i];
			_deqR[i] = tmp;
		}
	}
}

void	PmergeMe::v_sort_by_larger(void)
{
	int n = _vecL.size();
	for (int i = 1; i < n - 1; i++) {
		for (int j = i; j > 0; j--) {
			if (_vecL[j - 1] > _vecL[j]) {
				int tmp = _vecL[j - 1];
				_vecL[j - 1] = _vecL[j];
				_vecL[j] = tmp;
				tmp = _vecR[j - 1];
				_vecR[j - 1] = _vecR[j];
				_vecR[j] = tmp;
			}
		}
	}
}

void	PmergeMe::d_sort_by_larger(void)
{
	int n = _deqL.size();
	for (int i = 1; i < n - 1; i++) {
		for (int j = i; j > 0; j--) {
			if (_deqL[j - 1] > _deqL[j]) {
				int tmp = _deqL[j - 1];
				_deqL[j - 1] = _deqL[j];
				_deqL[j] = tmp;
				tmp = _deqR[j - 1];
				_deqR[j - 1] = _deqR[j];
				_deqR[j] = tmp;
			}
		}
	}
}

std::vector<int>	PmergeMe::v_jacobsthal_sequence(void)
{
	std::vector<int>	jacob(2, 0);
	std::vector<int>	index(1, 1);
	int					n = _vecR.size();

	jacob[1] = 1;
	while (jacob.back() < n) {
		int num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 1; k < jacob.size(); k++) {
		int	num = jacob[k + 1];
		while (num > jacob[k]) {
			index.push_back(num);
			num--;
		}
	}
	return (index);
}

std::deque<int>	PmergeMe::d_jacobsthal_sequence(void)
{
	std::deque<int>	jacob(2, 0);
	std::deque<int>	index(1, 1);
	int				n = _deqR.size();

	jacob[1] = 1;
	while (jacob.back() < n) {
		int num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 1; k < jacob.size(); k++) {
		int	num = jacob[k + 1];
		while (num > jacob[k]) {
			index.push_back(num);
			num--;
		}
	}
	return (index);
}

int		PmergeMe::v_binary_search(int number)
{
	int le = 0;
	int ri = _vecL.size() - 1;

	while (le < ri) {
		int mid = (ri - le) / 2 + le;
		if (number > _vecL[mid]) {
			le = mid + 1;
		} else if (number < _vecL[mid]) {
			ri = mid - 1;
		} else {
			return (mid);
		}
	}
	return (le);
}

int		PmergeMe::d_binary_search(int number)
{
	int le = 0;
	int ri = _deqL.size() - 1;

	while (le < ri) {
		int mid = (ri - le) / 2 + le;
		if (number > _deqL[mid]) {
			le = mid + 1;
		} else if (number < _deqL[mid]) {
			ri = mid - 1;
		} else {
			return (mid);
		}
	}
	return (le);
}

void	PmergeMe::v_insert(void)
{
	std::vector<int>	jacob;
	int jacobSize = jacob.size();
	int pendSize = _vecR.size() - 1;

	jacob = v_jacobsthal_sequence();
	int pos = v_binary_search(_vecR[0]);
	_vecL.insert(_vecL.begin() + pos, _vecR[0]);
	for (int i = 0; i < jacobSize; i++) {
		if (jacob[i] <= pendSize) {
			int index = jacob[i];
			pos = v_binary_search(_vecR[index]);
			_vecL.insert(_vecL.begin() + pos, _vecR[index]);
		}
	}
}

void	PmergeMe::d_insert(void)
{
	std::deque<int>	jacob;
	int jacobSize = jacob.size();
	int pendSize = _deqR.size() - 1;

	jacob = d_jacobsthal_sequence();
	int pos = d_binary_search(_deqR[0]);
	_deqL.insert(_deqL.begin() + pos, _deqR[0]);
	for (int i = 0; i < jacobSize; i++) {
		if (jacob[i] <= pendSize) {
			int index = jacob[i];
			pos = d_binary_search(_deqR[index]);
			_deqL.insert(_deqL.begin() + pos, _deqR[index]);
		}
	}
}

void	PmergeMe::sortVector(std::stringstream &stream)
{
	clock_t start = clock();

	this->v_pair_elements(stream);
	// std::cout << "Pair elements" << std::endl; // debug
	this->v_sort_pairs();
	// std::cout << "Sort pairs" << std::endl; // debug
	this->v_sort_by_larger();
	// std::cout << "Sort by larger" << std::endl; // debug
	this->v_insert();
	// std::cout << "Insert" << std::endl; // debug

	clock_t end = clock();

	this->_vecTime = (double(end - start) / double(CLOCKS_PER_SEC));
}

void	PmergeMe::sortDeque(std::stringstream &stream)
{
	clock_t start = clock();

	this->d_pair_elements(stream);
	// std::cout << "Pair elements" << std::endl; // debug
	this->d_sort_pairs();
	// std::cout << "Sort pairs" << std::endl; // debug
	this->d_sort_by_larger();
	// std::cout << "Sort by larger" << std::endl; // debug
	// this->d_insert();
	// std::cout << "Insert" << std::endl; // debug

	clock_t end = clock();

	this->_deqTime = (double(end - start) / double(CLOCKS_PER_SEC));
}


/* Public Member functions */

bool	PmergeMe::valid_sequence(int argc, char **argv,
		std::stringstream& stream)
{
	if (argc < 3)
		throw std::runtime_error("invalid usage");
	int num = 0;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);

		if (!(input >> num)) {
			return (false);
		} else if (num >= 0) {
			if (i > 1)
				stream << " ";
			stream << num;
		} else {
			return (false);
		}
	}
	// this->_input = stream;
	return (true);
}

void	PmergeMe::measure_merge_insertion_sort_time(std::stringstream& stream)
{
	this->sortVector(stream);
	// std::cout << "Sort vector" << std::endl; // debug
	this->sortDeque(stream);
	// std::cout << "Sort deque" << std::endl; // debug
}

void	PmergeMe::print_results(void)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vecL.size(); i++) {
		std::cout << _vecL[i];
		if (i + 1 != _vecL.size())
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _vecL.size() << " elements with std::vector : " << _vecTime << std::endl;
	std::cout << "Time to process a range of " << _deqL.size() << " elements with std::deque  : " << _deqTime << std::endl;
}
