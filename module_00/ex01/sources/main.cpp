/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:21 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 18:29:35 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	myPhoneBook;
	std::string	command;

	std::cout << "Welcome to the PhoneBook" << std::endl;
	while (1)
	{
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
	}
	return (0);
}
