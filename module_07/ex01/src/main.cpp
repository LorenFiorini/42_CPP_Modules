/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:14 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/04 19:01:06 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{
	int	array[] = {0, 1, 2, 3, 4};

	::iter(array, 5, print<int>);
	std::cout << std::endl;
	::iter(array, 5, increment<int>);
	::iter(array, 5, print<int>);
	std::cout << std::endl;
	::iter(array, 5, decrement<int>);
	::iter(array, 5, print<int>);
	std::cout << std::endl;

	char array2[] = {'a', 'b', 'c', 'd', 'e'};

	::iter(array2, 5, print<char>);
	std::cout << std::endl;
	::iter(array2, 5, increment<char>);
	::iter(array2, 5, print<char>);
	std::cout << std::endl;
	::iter(array2, 5, decrement<char>);
	::iter(array2, 5, print<char>);
	std::cout << std::endl;
	::iter(array2, 5, decrement<char>);
	::iter(array2, 5, print<char>);
	std::cout << std::endl;
	::iter(array2, 5, increment<char>);
	::iter(array2, 5, print<char>);
	std::cout << std::endl;

	float array3[] = {0.1f, 1.1f, 2.1f, 3.1f, 4.1f};
	::iter(array3, 5, print<float>);
	std::cout << std::endl;
	::iter(array3, 5, increment<float>);
	::iter(array3, 5, print<float>);
	std::cout << std::endl;
	::iter(array3, 5, decrement<float>);
	::iter(array3, 5, print<float>);

	return (0);
}
