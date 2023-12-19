/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:36:42 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 09:40:14 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

/** To-do:
 * 1. Check subject rules for dates and values
 */

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &src);
		~BitcoinExchange(void);

		double exchange(std::string date, double value);
};

#endif
