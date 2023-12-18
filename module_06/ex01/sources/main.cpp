/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 03:30:57 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	data;
	data.str = "Hello World!";

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << ptr->str << std::endl;
	std::cout << &data << std::endl;
	std::cout << ptr << std::endl;
	std::cout << raw << std::endl;
	
	return (0);
}
