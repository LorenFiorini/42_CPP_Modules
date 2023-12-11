/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:19:25 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/11 15:32:21 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private:
		int	_value;

	public:
		Data(void);
		Data(Data const &src);
		Data &operator=(Data const &rhs);
		~Data(void);

		int		getValue(void) const;
		void	setValue(int value);
};

#endif
