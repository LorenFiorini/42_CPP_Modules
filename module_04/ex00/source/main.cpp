/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:46 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 04:01:15 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta		= new Animal();
	const Animal		*j			= new Dog();
	const Animal		*i			= new Cat();
	const WrongAnimal	*wrong		= new WrongAnimal();
	const WrongAnimal	*wrongCat	= new WrongCat();

	std::cout	<< std::endl;
	std::cout	<< j->getType()			<< std::endl;
	std::cout	<< i->getType()			<< std::endl;
	std::cout	<< wrong->getType()		<< std::endl;
	std::cout	<< wrongCat->getType()	<< std::endl;
	
	std::cout	<< std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	wrongCat->makeSound();
	
	std::cout	<< std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
	return (0);
}
