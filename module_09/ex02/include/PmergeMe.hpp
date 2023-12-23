/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 06:32:50 by lfiorini         ###   ########.fr       */
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
		std::stringstream	_input;

		std::vector<int>	_vec;
		std::vector<int>	_pendVec;
		bool				_isVecSorted;
		double				_vecTime;

		std::deque<int>		_deq;
		std::deque<int>		_pendDeq;
		bool				_isDeqSorted;
		double				_deqTime;
		

		std::vector<int>	buildVecJacobSequence();
		std::deque<int>		buildDeqJacobSequence();
		//! Functions
		void	v_create_pairs(std::stringstream& stream);
		void	d_create_pairs(std::stringstream& stream);
		void	v_sort_pairs(void);
		void	d_sort_pairs(void);
		void	sortVecMainChain(void);
		void	sortDeqMainChain(void);
		void	v_binary_search(int number);
		void	deqBinarySearch(int number);
		void	insertVec(void);
		void	insertDeq(void);
	
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);
		~PmergeMe(void);

		bool	valid_args(int argc, char **argv, std::stringstream& stream);

		void    sortVector(std::stringstream &stream);
		void    sortDeque(std::stringstream &stream);
		
		void	printVec(int id);
		void	printDeq(int id);
		void	displayTime(void);
		std::vector<int>    getVector(void);
		std::deque<int>     getDeque(void);
		double	get_time_vec(void);
		double	get_time_deq(void);
		void	displayUnsortedSequence(int argc, char **argv);
		void	displaySortedSequence();

		void    setVecTime(double vecTime);
};

#endif
