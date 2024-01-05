/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:37:13 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/26 03:03:25 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
	: _expression("") { }

RPN::RPN(std::string expression)
	: _expression(expression)
{
	this->calculate();
}

RPN::RPN(RPN const &src)
	: _expression(src.getExpression())
{
	this->calculate();
}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src) {
		this->setExpression(src.getExpression());
		this->calculate();
	}
	return (*this);
}

RPN::~RPN(void) { }

std::string RPN::getExpression(void) const
{
	return (this->_expression);
}

void RPN::setExpression(std::string expression)
{
	this->_expression = expression;
	this->calculate();
}

std::string RPN::getResult(void) const
{
	return (this->_result);
}

void    RPN::calculate(void)
{
	std::stack<int> stk;
	std::string     result;
	int             a;
	int             b;

	for (size_t i = 0; i < this->_expression.length(); i++) {
		if (std::isdigit(this->_expression[i])) {
			stk.push(this->_expression[i] - '0');
		} else if (this->_expression[i] == '+'
				|| this->_expression[i] == '-'
				|| this->_expression[i] == '*'
				|| this->_expression[i] == '/') {
			if (stk.size() < 2) {
				throw std::runtime_error("Not enough numbers in the stack");
			}
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();
			if (this->_expression[i] == '+') {
				a += b;
			} else if (this->_expression[i] == '-') {
				a -= b;
			} else if (this->_expression[i] == '*') {
				a *= b;
			} else if (this->_expression[i] == '/') {
				if (b == 0) {
					throw std::runtime_error("Division by zero");
				} else {
					a /= b;
				}
			}
			stk.push(a);
			// std::cout << "a: " << a << std::endl;   // Debug
		} else if (this->_expression[i] != ' ') {
			throw std::runtime_error("Invalid character in expression");
		}
	}
	if (stk.size() != 1) {
		throw std::runtime_error("Invalid expression");
	}
	result = std::to_string(stk.top());
	this->_result = result;
}

std::ostream &operator<<(std::ostream &out, RPN const &rpn)
{
	out << rpn.getResult();
	return (out);
}

