/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 04:05:06 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/29 04:17:02 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

int main(int argc, char** argv) {
	// Check the arguments
	if (argc != 2) {
		std::cout << "Usage: harlFilter <log_level>" << std::endl;
		return 1;
	}
	// Get the log level
	std::string level = argv[1];

	// Create a Harl object
	Harl harl;

	// Call the complain method
	harl.complain(level);
	
	return 0;
}
