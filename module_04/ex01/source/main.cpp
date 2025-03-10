/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:41:46 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 05:51:00 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Dog basic;
    {
        Dog tmp = basic;
    }

    int n = 4;
    Animal* animals[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << i << ": ";
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << i << ": ";
        delete animals[i];
    }
    
    std::cout << std::endl;
    const Animal* meta  = new Animal();
    delete meta;
    return (0);
}
