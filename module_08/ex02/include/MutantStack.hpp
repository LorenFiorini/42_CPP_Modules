/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:30 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/22 03:48:25 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <iostream>
#include <stack>
#include <vector>
#include <list>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		MutantStack(void);
		MutantStack(const MutantStack &src);
		MutantStack &operator=(const MutantStack &op);
		virtual ~MutantStack(void);

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const;
		const_iterator cend() const;

		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

};

# include "../sources/MutantStack.tpp"


