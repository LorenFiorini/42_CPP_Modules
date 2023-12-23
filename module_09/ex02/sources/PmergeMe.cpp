/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 07:29:40 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Orthodox Canonical Form */

PmergeMe::PmergeMe(void) : _isVecSorted(false), _isDeqSorted(false) { }

PmergeMe& PmergeMe::operator=(PmergeMe const &src)
{
	if (this == &src) {
        this->_vec = src._vec;
        this->_pendVec = src._pendVec;
        this->_deq = src._deq;
        this->_pendDeq = src._pendDeq;
        this->_isVecSorted = src._isVecSorted;
        this->_isDeqSorted = src._isDeqSorted;
    }
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void) { }


/* Member Functions */

bool	PmergeMe::valid_args(int argc, char **argv,
        std::stringstream& stream) 
{
    if (argc < 3)
        throw std::runtime_error("invalid usage");
    int num = 0;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);
		
		if (!(input >> num) {
			return (false);
        } else if (num >= 0) {
            if (i > 1)
                stream << " ";
            stream << num;
        } else {
            return (false);
        }
	}
	return (true);
}

void	PmergeMe::v_create_pairs(std::stringstream& stream)
{
	int number = 0;
	
	while (stream >> number) {
		_pendVec.push_back(number);
		if (stream >> number) {
			_vec.push_back(number);
		}
	}
}

void	PmergeMe::d_create_pairs(std::stringstream& stream)
{
	int number = 0;
	
	while (stream >> number) {
		_pendDeq.push_back(number);
		if (stream >> number) {
			_deq.push_back(number);
		}
	}
}

void	PmergeMe::v_sort_pairs(void)
{
	for (size_t i = 0; i < _vec.size(); i++) {
		if (_vec[i] > _pendVec[i]) {
			// Check is swap() is c++98 compatible
			int tmp;

			tmp = _vec[i];
			_vec[i] = _pendVec[i];
			_pendVec[i] = tmp;
		}
	}
}

void	PmergeMe::d_sort_pairs(void)
{
	for (size_t i = 0; i < _deq.size(); i++) {
		if (_deq[i] > _pendDeq[i]) {
			int tmp;

			tmp = _deq[i];
			_deq[i] = _pendDeq[i];
			_pendDeq[i] = tmp;
		}
	}
}

void	PmergeMe::sortVecMainChain(void)
{
	std::vector<int>::iterator	mainIt = _vec.begin();
	std::vector<int>::iterator	pendIt = _pendVec.begin();
	
	while (mainIt + 1 != _vec.end()) {
		if (*mainIt > *(mainIt + 1)) {
			std::iter_swap(mainIt, mainIt + 1);
			std::iter_swap(pendIt, pendIt + 1);
            mainIt = _vec.begin();
            pendIt = _pendVec.begin();
		} else {
			mainIt++;
			pendIt++;
		}
	}
}

void	PmergeMe::sortDeqMainChain(void)
{
	std::deque<int>::iterator	mainIt = _deq.begin();
	std::deque<int>::iterator	pendIt = _pendDeq.begin();
	
	while (mainIt + 1 != _deq.end()) {
		if (*mainIt > *(mainIt + 1)) {
			std::iter_swap(mainIt, mainIt + 1);
			std::iter_swap(pendIt, pendIt + 1);
			mainIt = _deq.begin();
            pendIt = _pendDeq.begin();
		} else {
			mainIt++;
			pendIt++;
		}
	}
}

void PmergeMe::v_binary_search(int number)
{
	int le = 0;
	int ri = _vec.size() - 1;

	while (le <= ri) {
		int mid = (ri - le) / 2 + le;
		if (number > _vec[mid]) {
			le = mid + 1;
        } else if (number < _vec[mid]) {
            ri = mid - 1;
		} else {
			_vec.insert(_vec.begin() + mid, number);
			return ;
		}
	}

	_vec.insert(_vec.begin() + le, number);
}

void PmergeMe::deqBinarySearch(int number)
{
	int le = 0;
	int ri = _deq.size() - 1;

	while (le <= ri) {
		int mid = (ri - le) / 2 + le;
		if (number > _deq[mid]) {
			le = mid + 1;
        } else if (number < _deq[mid]) {
            ri = mid - 1;
		} else {
			_deq.insert(_deq.begin() + mid, number);
			return ;
		}
	}

	_deq.insert(_deq.begin() + le, number);
}

std::vector<int>	PmergeMe::buildVecJacobSequence()
{
	std::vector<int>	jacob;
	std::vector<int>	index;
	unsigned long 		k;
	int				size = _pendVec.size();
	int					num;

	jacob.push_back(0);
	jacob.push_back(1);
	for (num = 0; num < size;) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	index.push_back(1);
	for (k = 3; k < jacob.size(); k++) {
		int i = jacob[k];
		num = jacob[k] - jacob[k - 1];
		for (int j = num; j > 0; j--)
			index.push_back(i--);
	}
	return index;
}

std::deque<int>	PmergeMe::buildDeqJacobSequence()
{
	std::deque<int>	jacob;
	std::deque<int>	index;
	unsigned long 	k;
	int				size = _pendDeq.size();
	int					num;

	jacob.push_back(0);
	jacob.push_back(1);
	for (num = 0; num < size;) {
		num = jacob.back() + (jacob[jacob.size() - 2] * 2);
		jacob.push_back(num);
	}

	index.push_back(1);
	for (k = 3; k < jacob.size(); k++) {
		int i = jacob[k];
		num = jacob[k] - jacob[k - 1];
		for (int j = num; j > 0; j--)
			index.push_back(i--);
	}
	return index;
}

void	PmergeMe::insertVec(void)
{
	std::vector<int>	jacob = buildVecJacobSequence();
	int jacobSize = jacob.size();
	int pendSize = _pendVec.size() - 1;
	int i = 0;
	int index = 0;

	v_binary_search(_pendVec[0]);
	for (; i < jacobSize; i++) {
		if (jacob[i] <= pendSize) {
			index = jacob[i];
			v_binary_search(_pendVec[index]);
		}
		else
			continue;
	}

	std::vector<int>::iterator pos;
	pos = std::adjacent_find(_vec.begin(), _vec.end(), std::greater<int>());

	if (pos == _vec.end())
		_isVecSorted = true;
	else
		_isVecSorted = false;
}

void	PmergeMe::insertDeq(void)
{
	std::deque<int>	jacob = buildDeqJacobSequence();
	int jacobSize = jacob.size();
	int pendSize = _pendDeq.size() - 1;
	int i = 0;
	int index = 0;

	deqBinarySearch(_pendDeq[0]);
	for (; i < jacobSize; i++) {
		if (jacob[i] <= pendSize) {
			index = jacob[i];
			deqBinarySearch(_pendDeq[index]);
		}
		else
			continue;
	}

	std::deque<int>::iterator pos;
	pos = std::adjacent_find(_deq.begin(), _deq.end(), std::greater<int>());

	if (pos == _deq.end())
		_isDeqSorted = true;
	else
		_isDeqSorted = false;
}

void 	PmergeMe::displayUnsortedSequence(int argc, char **argv)
{
	std::stringstream stream;

	for (int i = 1; i < argc; i++) {
		std::stringstream	input(argv[i]);
		int number = 0;
		
		input >> number;
		std::cout << number << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::displaySortedSequence()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::displayTime(double vecTime, double decTime)
{
    std::cout   << std::fixed << std::setprecision(6);
	std::cout   << "Time to process a range of " << _vec.size()
                << " elements with std::vector : " << vecTime << std::endl;
	std::cout   << "Time to process a range of " << _deq.size()
                << " elements with std::deque  : " << decTime << std::endl;
}

void	PmergeMe::checkIfVecSorted()
{
	if (_isVecSorted == true) {
    	std::cout << "Vec container is sorted." << std::endl;
	} else {
    	std::cout << "Vec container is not sorted." << std::endl;
	}
}

void	PmergeMe::checkIfDeqSorted()
{
	if (_isDeqSorted == true) {
    	std::cout << "Deq container is sorted." << std::endl;
	} else {
    	std::cout << "Deq container is not sorted." << std::endl;
	}
}

void	PmergeMe::printVec(int id)
{
	if (id == MAIN) {
		std::cout << "main vec: ";
		
		for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	} else if (id == PEND) {
		std::cout << "pend vec: ";
		
		for (std::vector<int>::iterator it = _pendVec.begin(); it != _pendVec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	} else {
        throw std::runtime_error("invalid id");
    }
}

void	PmergeMe::printDeq(int id)
{
	if (id != MAIN && id != PEND)
		throw std::runtime_error("invalid id");

	if (id == MAIN) {
		std::cout << "main deq: ";
		
		for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	} else {
		std::cout << "pend deq: ";
		
		for (std::deque<int>::iterator it = _pendDeq.begin(); it != _pendDeq.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::sortVector(std::stringstream &stream)
{
    clock_t start = clock();
	
	pmerge.v_create_pairs(stream);
	pmerge.v_sort_pairs();
	pmerge.sortVecMainChain();
	pmerge.insertVec();
	
	clock_t end = clock();
	
	this->vecTime = (double(end - start) / double(CLOCKS_PER_SEC));
}

void    PmergeMe::sortDeque(std::stringstream &stream)
{
	clock_t start = clock();
	
	// stream.clear();
	// stream.seekg(0, std::ios::beg);
	pmerge.d_create_pairs(stream);
	pmerge.d_sort_pairs();
	pmerge.sortDeqMainChain();
	pmerge.insertDeq();
	
	clock_t end = clock();
	
	this->deqTime = (double(end - start) / double(CLOCKS_PER_SEC));
}
