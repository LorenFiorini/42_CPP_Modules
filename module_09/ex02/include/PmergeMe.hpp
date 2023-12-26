/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 02:28:15 by lfiorini         ###   ########.fr       */
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

# define A 2
# define B 4

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::vector<int>	_vec_tmp;
		std::deque<int>		_deque;
		std::deque<int>		_deq_tmp;

		std::vector<int>	_sequence;
		std::vector<int>	get_jacobsthal_vector(void);
		std::deque<int>		get_jacobsthal_deque(void);

		void				v_pair_elements(std::stringstream& stream);
		void				d_pair_elements(std::stringstream& stream);
		void				v_sort_pairs(void);
		void				d_sort_pairs(void);
		void				v_sort_main_chain(void);
		void				d_sort_main_chain(void);
		int					v_binary_search(int target);
		int					d_binary_search(int target);
		void				v_merge(void);
		void				d_merge(void);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe(void);

		void	v_print(int id);
		void	d_print(int id);
		bool	is_vector_sorted(void);
		bool	is_deque_sorted(void);

		double	sort_using_vector(std::stringstream &stream);
		double	sort_using_deque(std::stringstream &stream);
		bool	is_input_valid(int argc, char **argv, std::stringstream& stream);
		void	display_result(int argc, char **argv, double v_time, double d_time);

};

#endif
