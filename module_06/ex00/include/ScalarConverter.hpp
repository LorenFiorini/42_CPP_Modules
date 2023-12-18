/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:13:20 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 01:09:51 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

enum eType {
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL
};



class ScalarConverter
{
	public:
		static void	convert(std::string src);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter(void);

};

#endif
