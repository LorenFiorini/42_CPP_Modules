/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/22 03:31:20 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	size_t	max_size = 5;
	try {
		Span sp = Span(max_size);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: ";
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: ";
		std::cout << sp.longestSpan() << std::endl;
		
		std::cout << sp << std::endl;
		std::cout << "Try to add another number..." << std::endl;
		sp.addNumber(100);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Span sp = Span(max_size);
		sp.addNumber(17);
		std::vector<int> intArray(max_size - 1, 10);
		std::cout << "Try to add range of numbers" << std::endl;
		sp.addRange(intArray.begin(), intArray.end());
		std::cout << sp << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
		
	return (0);
}

