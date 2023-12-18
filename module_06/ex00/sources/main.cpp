/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:25 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 02:44:55 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) {
		try	{
			std::string str = argv[1];
			ScalarConverter::convert(str);
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
	} else {
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}

	return (0);
}
