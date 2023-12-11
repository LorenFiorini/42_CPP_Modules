/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 14:48:09 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	switch (rand() % 3) {
		case 0:
			std::cout << "A is generated." << std::endl;
			return new A;
		case 1:
			std::cout << "B is generated." << std::endl;
			return new B;
		case 2:
			std::cout << "C is generated." << std::endl;
			return new C;
	}
	return NULL;
}

void	identify(Base *p) {
	std::cout << "Identify by pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p) {
	std::cout << "Identify by reference: ";
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch(std::bad_cast &e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			return ;
		} catch(const std::bad_cast &e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				return ;
			} catch(const std::bad_cast &e) {
				std::cerr << e.what() << endl;
			}
			std::cerr << e.what() << endl;
		}
		std::cerr << e.what() << endl;
	}
}

int	main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
	return (0);
}
