/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:48:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 19:01:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T *array, size_t length, void (*f)(const T &))
{
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}
template <typename T>
void	print(T &a)
{
	std::cout << a << " ";
}

template <typename T>
void	print(const T &a)
{
	std::cout << a << " ";
}

template <typename T>
void	increment(T &a)
{
	a += 1;
}

template <typename T>
void	decrement(T &a)
{
	a -= 1;
}

// template <>
// void	increment(char &a)
// {
// 	if (a == 'z')
// 		a = 'a';
// 	else if (a == 'Z')
// 		a = 'A';
// 	else
// 		a++;
// }

// template <>
// void	decrement(char &a)
// {
// 	if (a == 'a')
// 		a = 'z';
// 	else if (a == 'A')
// 		a = 'Z';
// 	else
// 		a--;
// }

#endif
