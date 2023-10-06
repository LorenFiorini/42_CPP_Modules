/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:42:20 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 19:56:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			_contacts[8];
		int				_index;
		void			_displayOneContact(int index);
		void			_displayAllContacts(void);
		std::string		_getFieldInput(std::string field);
	public:
		PhoneBook();	// Constructor
		~PhoneBook();	// Destructor
		void			addContact(void);
		void			searchContact(void);
};

#endif
