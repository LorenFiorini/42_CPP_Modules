/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 05:54:58 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 19:57:20 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

std::string	PhoneBook::_getFieldInput(std::string field)
{
	std::string	input;

	std::cout << "Insert " << field << ": ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Contacts cannot have empty fields!" << std::endl;
		std::cout << "Please insert a valid " << field << ": ";
		std::getline(std::cin, input);
	}
	return (input);
}

void	PhoneBook::addContact(void)
{
	Contact	newContact;
	newContact.setFirstName(this->_getFieldInput("First name"));
	newContact.setLastName(this->_getFieldInput("Last name"));
	newContact.setNickname(this->_getFieldInput("Nickname"));
	newContact.setPhoneNumber(this->_getFieldInput("Phone number"));
	newContact.setDarkestSecret(this->_getFieldInput("Darkest secret"));
	this->_contacts[this->_index] = newContact;
	this->_index = (this->_index + 1) % 8;
	std::cout << "Contact added!" << std::endl;
}

void	PhoneBook::searchContact
