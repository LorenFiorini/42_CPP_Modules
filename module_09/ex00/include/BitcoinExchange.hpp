/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:36:42 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 02:38:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_rates;
		const std::string				_database;
		const std::string				_input_file;

		void					createDatabase(void);
		void					checkInputFile(void);
		bool					isValidDate(std::string date);
		void					processLine(std::string line);
		double					exchange(std::string date, double value);

		BitcoinExchange(void);

	public:
		BitcoinExchange(std::string database, std::string input);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &src);
		~BitcoinExchange(void);

		std::map<std::string, double>	&getRates(void);
		const std::string				&getDbFile(void) const;
		const std::string				&getInputFile(void) const;

		void	displayExchangeRates(void);
};

#endif
