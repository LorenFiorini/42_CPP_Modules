/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 09:23:31 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
	BitcoinExchange	*ftx = new BitcoinExchange("data.csv");

	if (argc != 2) {
		std::cout << "Usage: ./bitcoin filename" << std::endl;
		return (1);
	}

	return (0);
}
