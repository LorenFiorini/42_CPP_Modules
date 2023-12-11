/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:48:32 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename Container>
typename Container::iterator easyfind(Container &container, int num)
{
	typename Container::iterator it;

	it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		throw std::runtime_error("Not found");
	return (it);
}

#endif
