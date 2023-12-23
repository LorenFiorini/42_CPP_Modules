/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 20:15:02 by lfiorini         ###   ########.fr       */
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


void	PmergeMe::v_pair_elements(void)
{
	int num;

	for (size_t i = 0; i < this->_input.size(); i++) {
		num = this->_input[i];
		if (i % 2 == 0) {
			this->_vecL.push_back(num);
		} else {
			this->_vecR.push_back(num);
		}
	}
}

void	PmergeMe::d_pair_elements(void)
{
	int num;

	for (size_t i = 0; i < this->_input.size(); i++) {
		num = this->_input[i];
		if (i % 2 == 0) {
			this->_deqL.push_back(num);
		} else {
			this->_deqR.push_back(num);
		}
	}
}

void	PmergeMe::v_sort_pairs(void)
{
	for (size_t i = 0; i < this->_vecL.size(); i++) {
		if (this->_vecL[i] > this->_vecR[i]) {
			int tmp = this->_vecL[i];
			this->_vecL[i] = this->_vecR[i];
			this->_vecR[i] = tmp;
		}
	}
}

void	PmergeMe::d_sort_pairs(void)
{
	for (size_t i = 0; i < this->_deqL.size(); i++) {
		if (this->_deqL[i] > this->_deqR[i]) {
			int tmp = this->_deqL[i];
			this->_deqL[i] = this->_deqR[i];
			this->_deqR[i] = tmp;
		}
	}
}

void	PmergeMe::v_sort_by_larger(void)
{
	int n = this->_vecL.size();
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			if (this->_vecL[j] > this->_vecL[j + 1]) {
				int tmp = this->_vecL[j];
				this->_vecL[j] = this->_vecL[j + 1];
				this->_vecL[j + 1] = tmp;
				tmp = this->_vecR[j];
				this->_vecR[j] = this->_vecR[j + 1];
				this->_vecR[j + 1] = tmp;
			}
		}
	}
}

void	PmergeMe::d_sort_by_larger(void)
{
	int n = this->_deqL.size();
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			if (this->_deqL[j] > this->_deqL[j + 1]) {
				int tmp = this->_deqL[j];
				this->_deqL[j] = this->_deqL[j + 1];
				this->_deqL[j + 1] = tmp;
				tmp = this->_deqR[j];
				this->_deqR[j] = this->_deqR[j + 1];
				this->_deqR[j + 1] = tmp;
			}
		}
	}
}

std::vector<int>	PmergeMe::v_jacobsthal_sequence(void)
{
	std::vector<int>	jacob(2, 0);
	std::vector<int>	index(1, 1);
	int					n = this->_vecR.size();

	jacob[1] = 1;
	while (jacob.back() < n) {
		int num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 2; k + 1 < jacob.size(); k++) {
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
	int				n = this->_deqR.size();

	jacob[1] = 1;
	while (jacob.back() < n) {
		int num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	for (unsigned long k = 2; k + 1 < jacob.size(); k++) {
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
	int ri = this->_vecL.size() - 1;

	while (le <= ri) {
		int mid = (ri + le) / 2;
		if (number > this->_vecL[mid]) {
			le = mid + 1;
		} else if (number < this->_vecL[mid]) {
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
	int ri = this->_deqL.size() - 1;

	while (le <= ri) {
		int mid = (ri + le) / 2;
		if (number > this->_deqL[mid]) {
			le = mid + 1;
		} else if (number < this->_deqL[mid]) {
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


	jacob = v_jacobsthal_sequence();
	for (size_t i = 0; i < jacob.size(); i++)	std::cout << jacob[i] << " "; std::cout << std::endl;
	int pos = v_binary_search(this->_vecR[0]);
	this->_vecL.insert(this->_vecL.begin() + pos, this->_vecR[0]);
	for (unsigned int i = 0; i < jacob.size(); i++) {
		if (jacob[i] < (int) this->_vecR.size()) {
			int num = this->_vecR[jacob[i]];
			pos = v_binary_search(num);
			this->_vecL.insert(this->_vecL.begin() + pos, num);
		}
	}
}

void	PmergeMe::d_insert(void)
{
	std::deque<int>	jacob;

	jacob = d_jacobsthal_sequence();
	for (size_t i = 0; i < jacob.size(); i++)	std::cout << jacob[i] << " "; std::cout << std::endl;
	int pos = d_binary_search(this->_deqR[0]);
	this->_deqL.insert(this->_deqL.begin() + pos, this->_deqR[0]);
	for (unsigned int i = 0; i < jacob.size(); i++) {
		if (jacob[i] < (int) this->_deqR.size()) {
			int num = this->_deqR[jacob[i]];
			pos = d_binary_search(num);
			this->_deqL.insert(this->_deqL.begin() + pos, num);
		}
	}
}

void	PmergeMe::sortVector(void)
{
	clock_t start = clock();

	std::cout << "Vector Pair elements" << std::endl; // debug
	this->v_pair_elements();
	for (size_t i = 0; i < this->_vecL.size(); i++)	std::cout << this->_vecL[i] << " "; std::cout << std::endl;
	for (size_t i = 0; i < this->_vecR.size(); i++)	std::cout << this->_vecR[i] << " "; std::cout << std::endl;
	std::cout << "Vector Sort pairs" << std::endl; // debug
	this->v_sort_pairs();
	for (size_t i = 0; i < this->_vecL.size(); i++)	std::cout << this->_vecL[i] << " "; std::cout << std::endl;
	for (size_t i = 0; i < this->_vecR.size(); i++)	std::cout << this->_vecR[i] << " "; std::cout << std::endl;
	std::cout << "Vector Sort by larger" << std::endl; // debug
	this->v_sort_by_larger();
	for (size_t i = 0; i < this->_vecL.size(); i++)	std::cout << this->_vecL[i] << " "; std::cout << std::endl;
	for (size_t i = 0; i < this->_vecR.size(); i++)	std::cout << this->_vecR[i] << " "; std::cout << std::endl;
	std::cout << "Vector Insert" << std::endl; // debug
	this->v_insert();

	clock_t end = clock();

	this->_vecTime = (double(end - start) / double(CLOCKS_PER_SEC));
}

void	PmergeMe::sortDeque(void)
{
	clock_t start = clock();

	this->d_pair_elements();
	// std::cout << "Deque Pair elements" << std::endl; // debug
	this->d_sort_pairs();
	// std::cout << "Deque Sort pairs" << std::endl; // debug
	this->d_sort_by_larger();
	// std::cout << "Deque Sort by larger" << std::endl; // debug
	this->d_insert();
	// std::cout << "Deque Insert" << std::endl; // debug

	clock_t end = clock();

	this->_deqTime = (double(end - start) / double(CLOCKS_PER_SEC));
}


/* Public Member functions */

bool	PmergeMe::valid_sequence(int argc, char **argv)
{
	if (argc < 3)
		throw std::runtime_error("invalid usage");
	int num = 0;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);

		if (!(input >> num)) {
			return (false);
		} else if (num >= 0) {
			this->_input.push_back(num);
		} else {
			return (false);
		}
	}
	return (true);
}

void	PmergeMe::measure_merge_insertion_sort_time(void)
{
	std::cout << "Sort vector" << std::endl; // debug
	this->sortVector();
	for (size_t i = 0; i < this->_vecL.size(); i++)	std::cout << this->_vecL[i] << " "; std::cout << std::endl;
	for (size_t i = 0; i < this->_vecR.size(); i++)	std::cout << this->_vecR[i] << " "; std::cout << std::endl;
	std::cout << "Sort deque" << std::endl; // debug
	this->sortDeque();
	for (size_t i = 0; i < this->_deqL.size(); i++)	std::cout << this->_deqL[i] << " "; std::cout << std::endl;
	for (size_t i = 0; i < this->_deqR.size(); i++)	std::cout << this->_deqR[i] << " "; std::cout << std::endl;
}

void	PmergeMe::print_results(void)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->_input.size(); i++)
		std::cout << this->_input[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < this->_vecL.size(); i++)
		std::cout << this->_vecL[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < this->_deqL.size(); i++)
		std::cout << this->_deqL[i] << " ";
	
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << this->_vecL.size() << " elements with std::vector : " << _vecTime << std::endl;
	std::cout << "Time to process a range of " << this->_deqL.size() << " elements with std::deque  : " << _deqTime << std::endl;
}
