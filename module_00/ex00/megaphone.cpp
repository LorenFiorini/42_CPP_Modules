/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:41:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/08/29 16:04:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief This program takes a string as an argument and prints it in uppercase
 * @param argc The number of arguments passed to the program
 * @param argv The arguments passed to the program
*/

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j]; j++)
				str += toupper(argv[i][j]);
	}
	else
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << str << std::endl;
	return (0);
}
