/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:50:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = -5; i < 5; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
	}
	try
	{
		std::cout << easyfind(vec, -1) << std::endl;
		std::cout << easyfind(lst, -1) << std::endl;
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(lst, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
