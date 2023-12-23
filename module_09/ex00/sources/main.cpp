/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:41 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 04:29:06 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
	BitcoinExchange		*ftx;
	
	try {
		if (argc == 2) {
			ftx = new BitcoinExchange("data/data.csv", argv[1]);
			// std::map<std::string, double> &rates = ftx->getRates();
			// std::cout << "Database file: " << ftx->getDbFile() << std::endl;
			// std::cout << "Input file: " << ftx->getInputFile() << std::endl;
			// for (std::map<std::string, double>::iterator it = rates.begin(); it != rates.end(); it++) {
			// 	std::cout << it->first << ": " << it->second << std::endl;
			// }
			
			ftx->displayExchangeRates();
			delete ftx;
		} else {
			std::cout << "Usage: ./ftx <input_file>" << std::endl;
			throw std::runtime_error("could not open file.");
		}
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
