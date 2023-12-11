/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:09:13 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 16:13:43 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() { }

template <class T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &src) : std::stack<T, Container>(src) { }

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
		std::stack<T, Container>::operator=(rhs);
	return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}


template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}


template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cbegin() const
{
	return (this->c.cbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::cend() const
{
	return (this->c.cend());
}


template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crbegin() const
{
	return (this->c.crbegin());
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::crend() const
{
	return (this->c.crend());
}
