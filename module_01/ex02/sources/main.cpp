/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:42:16 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/15 03:56:19 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::left << std::setw(27) << "address of string: " << &str << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringREF: " << &stringREF << std::endl;
	
	std::cout << std::left << std::setw(28) << "value of string: " << str << std::endl;
	std::cout << "value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}

/** 
 * @brief Subject
 * Write a program that contains:
 * • A string variable initialized to "HI THIS IS BRAIN".
 * • stringPTR: A pointer to the string.
 * • stringREF: A reference to the string.
 * Your program has to print:
 * • The memory address of the string variable.
 * • The memory address held by stringPTR.
 * • The memory address held by stringREF.
 * And then:
 * • The value of the string variable.
 * • The value pointed to by stringPTR.
 * • The value pointed to by stringREF.
 * That’s all, no tricks. The goal of this exercise is to demystify references which can seem completely new. Although there are some little differences, this is another syntax for something you already do: address manipulation.
 *
 * @brief Expected output
 * $> ./a.out | cat -e
 * address of string: 0x7ffd5fbff5e0$
*/