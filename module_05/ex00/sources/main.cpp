/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/08 09:22:31 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat *anna = new Bureaucrat("Anna", 2);
		std::cout << *anna << std::endl;
		anna->incrementGrade();
		std::cout << *anna << std::endl;
		delete anna;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat *bob = new Bureaucrat("Bob", 149);
		std::cout << *bob << std::endl;
		bob->decrementGrade();
		std::cout << *bob << std::endl;
		bob->decrementGrade();
		std::cout << *bob << std::endl;
		delete bob;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat *charlie = new Bureaucrat("Charlie", -5);
		std::cout << *charlie << std::endl;
		charlie->incrementGrade();
		std::cout << *charlie << std::endl;
		delete charlie;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat *daniel = new Bureaucrat("Daniel", 151);
		std::cout << *daniel << std::endl;
		daniel->decrementGrade();
		std::cout << *daniel << std::endl;
		delete daniel;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
