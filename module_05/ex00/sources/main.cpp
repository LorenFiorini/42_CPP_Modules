/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/08 12:12:31 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		std::cout << "Creating a bureaucrat with grade 2 ..." << std::endl;
		Bureaucrat *anna = new Bureaucrat("Anna", 2);
		std::cout << *anna << std::endl;
		std::cout << "Incrementing grade ..." << std::endl;
		anna->incrementGrade();
		std::cout << *anna << std::endl;
		delete anna;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating a bureaucrat with grade 149 ..." << std::endl;
		Bureaucrat *bob = new Bureaucrat("Bob", 149);
		std::cout << *bob << std::endl;
		std::cout << "Decrementing grade ..." << std::endl;
		bob->decrementGrade();
		std::cout << *bob << std::endl;
		std::cout << "Decrementing grade ..." << std::endl;
		bob->decrementGrade();
		std::cout << *bob << std::endl;
		delete bob;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating a bureaucrat with grade -5 ..." << std::endl;
		Bureaucrat *charlie = new Bureaucrat("Charlie", -5);
		std::cout << *charlie << std::endl;
		delete charlie;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating a bureaucrat with grade 151 ..." << std::endl;
		Bureaucrat *daniel = new Bureaucrat("Daniel", 151);
		std::cout << *daniel << std::endl;
		delete daniel;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
