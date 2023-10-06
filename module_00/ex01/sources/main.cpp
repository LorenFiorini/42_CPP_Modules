/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:21 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 21:25:59 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	myPhoneBook;
	std::string	command;

	std::cout << "Welcome to the PhoneBook!\n" << std::endl;
	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Please enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContact();
		else
			std::cout << "Invalid command" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
