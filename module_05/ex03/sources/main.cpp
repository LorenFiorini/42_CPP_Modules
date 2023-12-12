/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:52 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 14:13:26 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*a;
	Bureaucrat	*b;
	Form		*f;

	try {
		std::cout << "Creating a bureaucrat with grade 2 ..." << std::endl;
		a = new Bureaucrat("Anna", 2);
		std::cout << a << std::endl;
		std::cout << "Incrementing grade ..." << std::endl;
		a->incrementGrade();
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating a bureaucrat with grade 149 ..." << std::endl;
		b = new Bureaucrat("Bob", 149);
		std::cout << b << std::endl;
		std::cout << b << std::endl;
		std::cout << "Decrementing grade ..." << std::endl;
		b->decrementGrade();
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating a form ..." << std::endl;
		f = new Form("Form", 75, 75);
		std::cout << (*f) << std::endl;
		std::cout << "Signing form with Anna ..." << std::endl;
		a->signForm(*f);
		std::cout << (*f) << std::endl;
		std::cout << "Signing form with Bob ..." << std::endl;
		b->signForm(*f);
		std::cout << (*f) << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
