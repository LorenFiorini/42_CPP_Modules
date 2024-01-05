/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:00 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 03:03:06 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::string _expression;
		std::string _result;

	public:
		RPN(void);
		RPN(std::string expression);
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		~RPN(void);


		std::string getExpression(void) const;
		void        setExpression(std::string expression);
		std::string getResult(void) const;

		void        calculate(void);
};

std::ostream &operator<<(std::ostream &out, RPN const &rpn);

#endif
