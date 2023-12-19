/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:56:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/19 07:51:56 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T> 
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator	it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("Exception: Integer not found");
	}
		
	return (it);
}

#endif
