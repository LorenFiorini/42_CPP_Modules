/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:36:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 09:38:55 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _rates(src._rates) { }

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src) {
		this->_rates = src._rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream		file;
	std::string			line;
	std::string			date;
	std::string			rate;

	file.open(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	while (std::getline(file, line)) {
		std::size_t pos = line.find(",");
		date = line.substr(0, pos);
		rate = line.substr(pos + 1);
		this->_rates[date] = std::stod(rate);
	}
	file.close();
}

double			BitcoinExchange::exchange(std::string date, double value)
{
	double		rate;

	rate = this->_rates.lower_bound(date)->second;
	return (value * rate);
}


