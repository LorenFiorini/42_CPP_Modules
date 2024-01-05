/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 02:44:58 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
	BitcoinExchange	*ftx;

	try {
		if (argc != 2) {
			std::cout << "Usage: ./ftx <input_file>" << std::endl;
			throw std::runtime_error("could not open file.");
		}
		ftx = new BitcoinExchange("data/data.csv", argv[1]);
		ftx->displayExchangeRates();
		delete ftx;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
