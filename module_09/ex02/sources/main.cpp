/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 06:24:39 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// double	sortWithVector(std::stringstream &stream, PmergeMe &pmerge)
// {
// 	clock_t start = clock();
	
// 	pmerge.v_create_pairs(stream);
// 	pmerge.v_sort_pairs();
// 	pmerge.sortVecMainChain();
// 	pmerge.insertVec();
	
// 	clock_t end = clock();
// 	double vecTime = double(end - start) / double(CLOCKS_PER_SEC);
	
// 	return (vecTime);
// }

// double	sortWithDeque(std::stringstream &stream, PmergeMe &pmerge)
// {
// 	clock_t start = clock();
	
// 	stream.clear();
// 	stream.seekg(0, std::ios::beg);
// 	pmerge.d_create_pairs(stream);
// 	pmerge.d_sort_pairs();
// 	pmerge.sortDeqMainChain();
// 	pmerge.insertDeq();
	
// 	clock_t end = clock();
// 	double deqTime = double(end - start) / double(CLOCKS_PER_SEC);
	
// 	return (deqTime);
// }

void	mergeInsertionAlgorithm(PmergeMe &pmerge, std::stringstream &stream)
{
	clock_t start;
    clock_t end;

    start = clock();
	pmerge.sortVector(stream);
    end = clock();
    pmerge.setVecTime(double(end - start) / double(CLOCKS_PER_SEC));

    start = clock();
	double deqTime = sortWithDeque(stream, pmerge);

	std::cout << "Before: ";
	pmerge.displayUnsortedSequence(argc, argv);
	std::cout << "After : ";
	pmerge.displaySortedSequence();
	pmerge.displayTime(vecTime, deqTime);
}

int main (int argc, char **argv)
{
    PmergeMe            *pmerge;
    std::stringstream 	stream;

	try {
        pmerge = new PmergeMe();
        assert(pmerge->valid_args(argc, argv, stream));
		mergeInsertionAlgorithm(pmerge, stream);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
        return (1);
	}

	return (0);
}
