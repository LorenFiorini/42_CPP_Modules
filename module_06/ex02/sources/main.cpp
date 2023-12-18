/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:42:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 03:27:12 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	Base *random = generate();
	identify(random);
	identify(*random);

	delete random;
	return (0);
}



Base	*generate(void) {
	std::srand(time(0));
	
	int i = rand() % 3;
	switch (i) {
		case 0:
			std::cout << "A is generated." << std::endl;
			return (new A);
		case 1:
			std::cout << "B is generated." << std::endl;
			return (new B);
		case 2:
			std::cout << "C is generated." << std::endl;
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "ERROR" << std::endl;
}

void	identify(Base &p)
{	
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			(void) dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				(void) dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "ERROR" << std::endl;
			}
		}
	}
}
