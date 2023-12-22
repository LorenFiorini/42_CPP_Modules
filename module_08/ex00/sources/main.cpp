/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/22 01:45:44 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template <typename T> void printContainer(T &container);


int main(void)
{
	try {
		// 1. Test with vector
		std::vector<int>			vec;
		std::vector<int>::iterator	it;
		for (int i = 0; i < 10; i += 2) {
			vec.push_back(i);
		}

		std::cout << "\nTest with vector" << std::endl;
		printContainer(vec);		
		std::cout << "Searching for 2 and 5" << std::endl;
		it = easyfind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(vec, 5);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		// 2. Test with list
		std::list<int>				lst;
		std::list<int>::iterator	it;
		for (int i = 1; i < 10; i += 2) {
			lst.push_back(i);
		}
		
		std::cout << "\nTest with list" << std::endl;
		printContainer(lst);
		std::cout << "Searching for 1 and 4" << std::endl;
		it = easyfind(lst, 1);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(lst, 4);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}

template <typename T>
void printContainer(T &container)
{
	typename T::iterator	it;
	
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
