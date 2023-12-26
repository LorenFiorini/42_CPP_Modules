/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 02:24:52 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

double	sort_using_vector(std::stringstream &stream, PmergeMe &pmerge);
double	sort_using_deque(std::stringstream &stream, PmergeMe &pmerge);
void	merge_insertion_sort(int argc, char **argv);

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

	pmerge.display_result(argc, argv, v_time, d_time);
	
	pmerge.v_print(A);	// Debug
	// pmerge.v_print(B);	// Debug
	pmerge.is_vector_sorted();	// Debug
	pmerge.d_print(A);	// Debug
	// pmerge.d_print(B);	// Debug
	pmerge.is_deque_sorted();	// Debug
}

// double	sort_using_vector(std::stringstream &stream, PmergeMe &pmerge)
// {
// 	clock_t start = clock();
	
// 	pmerge.v_pair_elements(stream);
// 	// pmerge.v_print(A);	// Debug
// 	// pmerge.v_print(B);	// Debug

// 	pmerge.v_sort_pairs();
// 	pmerge.v_sort_main_chain();
// 	pmerge.v_merge();
// 	// pmerge.v_print(A);	// Debug
// 	clock_t end = clock();
	
// 	double v_time = double(end - start) / double(CLOCKS_PER_SEC);
	
// 	return (v_time);
// }

// double	sort_using_deque(std::stringstream &stream, PmergeMe &pmerge)
// {
// 	clock_t start = clock();
	
// 	stream.clear();
// 	stream.seekg(0, std::ios::beg);
// 	pmerge.d_pair_elements(stream);
// 	// pmerge.d_print(A);	// Debug
// 	// pmerge.d_print(B);	// Debug

// 	pmerge.d_sort_pairs();
// 	pmerge.d_sort_main_chain();
// 	pmerge.d_merge();
// 	// pmerge.d_print(A);	// Debug
// 	clock_t end = clock();
	
// 	double d_time = double(end - start) / double(CLOCKS_PER_SEC);
	
// 	return (d_time);
// }

