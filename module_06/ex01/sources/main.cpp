/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:33:41 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	// Serialize and deserialize a stack variable
	Serializer	s;
	Data		stk;
	Data		*stkPtr;
	uintptr_t	stkAddr;
	Data		*stkPtrDes;

	stk.value	= 42;
	stkPtr		= &stk;
	stkAddr		= s.serialize(stkPtr);
	stkPtrDes	= s.deserialize(stkAddr);

	std::cout << "stkPtr->value: " << stkPtr->value << std::endl;
	std::cout << "stkAddr: " << stkAddr << std::endl;
	std::cout << "stkPtrDes->value: " << stkPtrDes->value << std::endl;

	// Serialize and deserialize a heap variable
	Data		*heap;
	uintptr_t	heapAddr;
	Data		*heapDes;

	heap		= new Data;
	heap->value	= 21;
	heapAddr	= s.serialize(heap);
	heapDes		= s.deserialize(heapAddr);

	std::cout << "heap->value: " << heap->value << std::endl;
	std::cout << "heapAddr: " << heapAddr << std::endl;
	std::cout << "heapDes->value: " << heapDes->value << std::endl;

	delete heap;
	return (0);
}
