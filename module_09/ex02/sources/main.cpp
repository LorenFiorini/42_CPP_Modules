/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 11:04:28 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{

	try
	{
		std::stringstream	stream;
		PmergeMe			pmerge;

		assert(pmerge.valid_sequence(argc, argv, stream));
		std::cout << "Valid sequence" << std::endl; // Debug
		pmerge.measure_merge_insertion_sort_time(stream);
		std::cout << "Time measured" << std::endl; // Debug
		pmerge.print_results();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
