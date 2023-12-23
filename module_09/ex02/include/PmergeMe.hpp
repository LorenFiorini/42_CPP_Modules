/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 19:43:16 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>

/** To-do:
 * 1. Check is swap() is c++98 compatible
 * 2. Try to use templates
*/

enum eType {
	MAIN = 0x01,
	PEND = 0x02,
	VECTOR = 0x04,
	DEQUE = 0x08
};

class PmergeMe
{
	private:
		std::vector<int>	_input;

		std::vector<int>	_vecL;
		std::vector<int>	_vecR;
		double				_vecTime;

		std::deque<int>		_deqL;
		std::deque<int>		_deqR;
		double				_deqTime;


		void				v_pair_elements(void);
		void				d_pair_elements(void);
		void				v_sort_pairs(void);
		void				d_sort_pairs(void);
		void				v_sort_by_larger(void);
		void				d_sort_by_larger(void);
		std::vector<int>	v_jacobsthal_sequence(void);
		std::deque<int>		d_jacobsthal_sequence(void);
		int					v_binary_search(int number);
		int					d_binary_search(int number);
		void				v_insert(void);
		void				d_insert(void);
		void				sortVector(void);
		void				sortDeque(void);

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);
		~PmergeMe(void);

		bool	valid_sequence(int argc, char **argv);
		void	measure_merge_insertion_sort_time(void);
		void	print_results(void);
};

#endif
