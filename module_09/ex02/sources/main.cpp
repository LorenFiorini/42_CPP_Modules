/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 03:11:16 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	merge_insertion_sort(int argc, char **argv) 
{
	std::stringstream 	stream;
	PmergeMe			pmerge;

	if (argc < 3)
		throw std::runtime_error("invalid usage");
	else if (pmerge.is_input_valid(argc, argv, stream) == false)
		throw std::runtime_error("invalid arguments");
		
	double v_time = pmerge.sort_using_vector(stream);
	double d_time = pmerge.sort_using_deque(stream);

	pmerge.display_result(v_time, d_time);
}

int main (int argc, char **argv) 
{
	try {
		merge_insertion_sort(argc, argv);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
