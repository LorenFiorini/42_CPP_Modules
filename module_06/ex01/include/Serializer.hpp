/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:39 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:20:01 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &rhs);
		~Serializer(void);

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
};

#endif
