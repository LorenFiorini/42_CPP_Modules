/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 23:14:00 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <vector>
# include <deque>
# include <math.h>
# include <algorithm>
# include <ctime>

# define A 1
# define B 2

# define RED 	"\033[1;31m"
# define GREEN 	"\033[1;32m"
# define RESET 	"\033[0m"\

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::vector<int>	_vec_tmp;
		std::deque<int>		_deq;
		std::deque<int>		_deq_tmp;

		bool				_isVecSorted;
		bool				_isDeqSorted;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe(void);


		bool	validateArguments(int argc, char **argv, std::stringstream& stream);
		void	v_pair_elements(std::stringstream& stream);
		void	d_pair_elements(std::stringstream& stream);
		void	v_sort_pairs(void);
		void	d_sort_pairs(void);
		void	v_sort_main_chain(void);
		void	d_sort_main_chain(void);
		void	v_binary_search(int number);
		void	d_binary_search(int number);
		void	insertVec(void);
		void	insertDeq(void);
	
		std::vector<int>	get_jacobsthal_vector(void);
		std::deque<int>		get_jacobsthal_deque(void);

		void	printVec(int id);
		void	printDeq(int id);
		void	checkIfVecSorted(void);
		void	checkIfDeqSorted(void);
		void	displayTime(double vecTime, double decTime);
		void	displayUnsortedSequence(int argc, char **argv);
		void	displaySortedSequence(void);
};

#endif
