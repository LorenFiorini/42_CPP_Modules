/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 23:00:47 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

double	sortWithVector(std::stringstream &stream, PmergeMe &pmerge)
{
	clock_t start = clock();
	
	pmerge.v_pair_elements(stream);
	pmerge.v_sort_pairs();
	pmerge.v_sort_main_chain();
	pmerge.insertVec();
	
	clock_t end = clock();
	double vecTime = double(end - start) / double(CLOCKS_PER_SEC);
	
	return vecTime;
}

double	sortWithDeque(std::stringstream &stream, PmergeMe &pmerge)
{
	clock_t start = clock();
	
	stream.clear();
	stream.seekg(0, std::ios::beg);
	pmerge.d_pair_elements(stream);
	pmerge.d_sort_pairs();
	pmerge.d_sort_main_chain();
	pmerge.insertDeq();
	
	clock_t end = clock();
	double deqTime = double(end - start) / double(CLOCKS_PER_SEC);
	
	return deqTime;
}

void	mergeInsertionAlgorithm(int argc, char **argv) 
{
	std::stringstream 	stream;
	PmergeMe			pmerge;

	if (!pmerge.validateArguments(argc, argv, stream))
		throw std::runtime_error("invalid arguments");
		
	double vecTime = sortWithVector(stream, pmerge);
	double deqTime = sortWithDeque(stream, pmerge);

	std::cout << "Before: ";
	pmerge.displayUnsortedSequence(argc, argv);
	std::cout << "After : ";
	pmerge.displaySortedSequence();
	pmerge.displayTime(vecTime, deqTime);
	
	pmerge.checkIfVecSorted();
	pmerge.checkIfDeqSorted();
}

int main (int argc, char **argv) 
{
	if (argc < 3)
	{
		std::cerr << RED << "Error: invalid usage" << std::endl;
		return EXIT_FAILURE;
	}
	
	try
	{
		mergeInsertionAlgorithm(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
