/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:41:56 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/06 20:41:45 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
	public:
		Contact();		// Constructor
		~Contact();		// Destructor
		void			setFirstName(std::string firstName);
		void			setLastName(std::string lastName);
		void			setNickname(std::string nickname);
		void			setPhoneNumber(std::string phoneNumber);
		void			setDarkestSecret(std::string darkestSecret);
		std::string		getFirstName(void);
		std::string		getLastName(void);
		std::string		getNickname(void);
		std::string		getPhoneNumber(void);
		std::string		getDarkestSecret(void);
};

#endif

/* Lorenzo Fiorini */
