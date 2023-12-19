/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:48:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 01:01:36 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F fun) {
    for (size_t i = 0; i < length; i++) {
        fun(array[i]);
    }
}

template <typename T>
void	my_print(T &a)
{
	std::cout << a << " ";
}

#endif
