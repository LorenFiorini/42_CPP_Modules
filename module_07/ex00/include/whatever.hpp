/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:52:01 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 00:50:57 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T> void	swap(T &a, T &b) {
	T tmp;
	
	tmp	= a;
	a	= b;
	b	= tmp;
}

template <typename T> T&	min(T &a, T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T&	max(T &a, T &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif
