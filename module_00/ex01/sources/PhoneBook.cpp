/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 05:54:58 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 21:26:52 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->_numberOfContacts	= 0;
	this->_index			= 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
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
	this->_numberOfContacts = std::min(this->_numberOfContacts + 1, 8);
	std::cout << "Contact added!" << std::endl;
}
/*
SEARCH: display a specific contact
◦ Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
◦ Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
◦ Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.
*/
void	PhoneBook::searchContact(void)
{
	this->_displayAllContacts();
	int	index;

	std::cout << "Please insert the index of the contact you want to display: ";
	std::cin >> index;
	while (std::cin.fail() || index < 0 || index >= this->_numberOfContacts)
	{
		std::cout << "Invalid index" << std::endl;
		std::cout << "Please insert the index of the contact you want to display: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> index;
	}
	if (this->_numberOfContacts == 8)
		index = (this->_index + index) % 8;
	this->_displayOneContact(index);
	std::cin.clear();
}

/**	Private members 
 * 
*/

std::string	PhoneBook::_truncateString(std::string str)
{
	std::string	truncated;
	if (str.length() > 10)
	{
		truncated = str.substr(0, 9);
		truncated.append(".");
	}
	else
		truncated = str;
	return (truncated);
}

void	PhoneBook::_displayOneContact(int index)
{
	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
}

void	PhoneBook::_displayAllContacts(void)
{
	int	oldestContact = 0;

	if (this->_numberOfContacts == 8)
		oldestContact = this->_index;

	for (int i = 0; i < this->_numberOfContacts; i++)
	{
		int	index = (oldestContact + i) % this->_numberOfContacts;
		std::string	firstName = this->_truncateString(this->_contacts[index].getFirstName());
		std::string	lastName = this->_truncateString(this->_contacts[index].getLastName());
		std::string	nickname = this->_truncateString(this->_contacts[index].getNickname());
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
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
