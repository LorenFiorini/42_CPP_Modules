/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/15 02:14:48 by lfiorini         ###   ########.fr       */
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

	stk.setValue(42);
	stkPtr		= &stk;
	stkAddr		= s.serialize(stkPtr);
	stkPtrDes	= s.deserialize(stkAddr);

	std::cout << "stkPtr->getValue()" << stkPtr->getValue() << std::endl;
	std::cout << "stkAddr: " << stkAddr << std::endl;
	std::cout << "stkPtrDesvalue: " << stkPtrDes->getValue() << std::endl;

	// Serialize and deserialize a heap variable
	Data		*heap;
	uintptr_t	heapAddr;
	Data		*heapDes;

	heap		= new Data;
	heap->setValue(21);
	heapAddr	= s.serialize(heap);
	heapDes		= s.deserialize(heapAddr);

	std::cout << "heap->value: " << heap->getValue() << std::endl;
	std::cout << "heapAddr: " << heapAddr << std::endl;
	std::cout << "heapDes->value: " << heapDes->getValue() << std::endl;

	delete heap;
	return (0);
}
