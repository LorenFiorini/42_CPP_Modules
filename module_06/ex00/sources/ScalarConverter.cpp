/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:13:23 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 02:21:53 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


ScalerConverter::ScalerConverter(void) {
}

ScalerConverter::ScalerConverter(ScalerConverter const &src) {
	(void)src;
}

ScalerConverter &ScalerConverter::operator=(ScalerConverter const &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

ScalerConverter::~ScalerConverter(void) {
}

void	ScalerConverter::convert(std::string str) {
	try {
		Parser::parse_input(str);
		Parser::display_conversion();
	} catch (const std::exception &e) {
		throw e;
	}
}
