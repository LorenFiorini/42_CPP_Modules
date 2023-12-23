/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:36:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/23 04:29:36 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
	: _rates(src._rates) { }

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src) {
		this->_rates = src._rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(std::string database, std::string input)
	: _database(database), _input_file(input)
{
	try {
		this->createDatabase();
		this->checkInputFile();
	} catch (std::exception &e) {
		throw std::runtime_error(e.what());
	}
}


void			BitcoinExchange::createDatabase(void)
{
	std::ifstream		file;
	std::string			line;
	std::string			date;
	double				rate;

	try {
		file.open(this->_database);
		if (!file.is_open())
			throw std::runtime_error("could not open file.");
		while (std::getline(file, line)) {
			std::size_t pos = line.find(",");
			date = line.substr(0, pos);
			if (!this->isValidDate(date))
				continue ;
			rate = std::stod(line.substr(pos + 1));
			this->_rates[date] = rate;
		}
		file.close();
	} catch (std::exception &e) {
		throw std::runtime_error(e.what());
	}
}

void		BitcoinExchange::checkInputFile(void)
{
	std::ifstream		file;

	try {
		file.open(this->_input_file);
		if (!file.is_open())
			throw std::runtime_error("could not open file.");
		file.close();
	} catch (std::exception &e) {
		throw std::runtime_error(e.what());
	}
}

bool		BitcoinExchange::isValidDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	try {
		int	year	= std::stoi(date.substr(0, 4));
		int	month	= std::stoi(date.substr(5, 2));
		int	day		= std::stoi(date.substr(8, 2));
		if ((month < 1 || month > 12
			|| day < 1 || day > 31)
			|| ((month == 4 || month == 6 || month == 9 || month == 11)
				&& day > 30))
			return (false);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (month == 2 && day > 29)
				return (false);
		} else if (month == 2 && day > 28)
			return (false);
	} catch (std::exception &e) {
		return (false);
	}
	return (true);
}

void			BitcoinExchange::processLine(std::string line)
{
	std::size_t		pos		= line.find(" | ");
	std::string		date	= line.substr(0, pos);

	if (pos == std::string::npos || this->isValidDate(date) == false) {
		// std::cout << "Error: bad input => " << line <<  "npos or invalid date" << std::endl;
		std::cout << "Error: bad input => " << line << std::endl;	
		return ;	
	}

	try {
		std::string	number = line.substr(pos + 3);
		// std::cout << "number: " << number << std::endl; // Debug
		double		value = std::stod(number); 
		// std::size_t	decimal = number.find(".");		// Debug
		// std::cout << "value: " << value << std::endl;	// Debug
		if (value < (double) 0) {
			std::cout << "Error: not a positive number." << std::endl;
		} else if (value > (double) 1000) {
			std::cout << "Error: too large a number." << std::endl;
		} else {
			std::cout << date << " => " << value << " = ";
			
			std::cout << std::fixed << std::setprecision(2) << this->exchange(date, value) << std::endl;
		}
	} catch (std::exception &e) {
		// std::cout << "Exception: " << e.what() << std::endl; // Debug
		std::cout << "Error: bad input => " << line << std::endl;
	}
	
}


double			BitcoinExchange::exchange(std::string date, double value)
{
	double	rate;

	rate = this->_rates.lower_bound(date)->second;
	return (value * rate);
}

/* Getters */

std::map<std::string, double>	&BitcoinExchange::getRates(void)
{
	return (this->_rates);
}

const std::string				&BitcoinExchange::getDbFile(void) const
{
	return (this->_database);
}

const std::string				&BitcoinExchange::getInputFile(void) const
{
	return (this->_input_file);
}


/* Display */

void	BitcoinExchange::displayExchangeRates(void)
{
	std::ifstream		file;
	std::string			line;

	try {
		file.open(this->_input_file);
		if (!file.is_open())
			throw std::runtime_error("could not open file.");
		std::getline(file, line);
		while (std::getline(file, line)) {
			this->processLine(line);
		}
		file.close();
	} catch (std::exception &e) {
		throw std::runtime_error(e.what());
	}
}
