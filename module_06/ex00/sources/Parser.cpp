/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:35:55 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 02:41:42 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

/* Orthodox Canonical Class Form */

Parser::Parser(void) {
}

Parser::Parser(Parser const &src) {
	(void)src;
}

Parser &Parser::operator=(Parser const &rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return (*this);
}

Parser::~Parser(void) {
}


/* Static Variables */

std::string Parser::_str = "";
eType		Parser::_type = OTHER;


/* Exceptions */
const char *Parser::InvalidStringException::what() const throw() {
	return ("InvalidStringException: the string is invalid for conversion");
}


/* Parse Input String */

void	Parser::parse_input(std::string &str)
{
	try {
		_setInput(str);
		_setType(this->_input);
	} catch (const std::exception &e) {
		throw InputInvalidException();
	}
}

void	Parser::_setInput(std::string str)
{
	if (str.length() == 0) {
		throw InputInvalidException();
	}
	std::string	white_spaces = " \t\n\v\f\r";
	size_t		start	= str.find_first_not_of(white_spaces);
	size_t		end		= str.find_last_not_of(white_spaces);

	if (start != std::string::npos && end != std::string::npos) {
		this->_input = str.substr(start, end - start + 1);
	}
}

void	Parser::_setType(std::string str)
{
	if (_isChar(str)) {
		this->_type = CHAR;
	} else if (_isInt(str)) {
		this->_type = INT;
	} else if (_isFloat(str)) {
		this->_type = FLOAT;
	} else if (_isDouble(str)) {
		this->_type = DOUBLE;
	} else if (_isPseudoliteral(str)) {
		this->_type = PSEUDOLITERAL;
	} else {
		throw InputInvalidException();
	}
}

bool	Parser::_isPseudoliteral(std::string str) {
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan") {
		return (true);
	}
	return (false);
}

bool	Parser::_isChar(std::string str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		return (true);
	}
	return (false);
}

bool	Parser::_isInt(std::string str) {
	for (size_t	i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (!isdigit(str[i])) {
			return (false);
		}
	}
	long num = atol(str.c_str());
	long max = std::numeric_limits<int>::max();
	long min = std::numeric_limits<int>::min();
	return (num >= min && num <= max);
}

bool	Parser::_isFloat(std::string str) {
	size_t	count_dot = 0;
	for (; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (count_dot < 1 && str[i] == '.') {
			count_dot++;
		} else if (!isdigit(str[i]) && !(i == str.length() - 1 && str[i] == 'f')) {
			return (false);
		}
	}
	double num = strtod(str.c_str(), NULL);
	double max = std::numeric_limits<float>::max();
	double min = -std::numeric_limits<float>::max();
	return (num >= min && num <= max);
}

bool 	Parser::_isDouble(std::string str) {
	size_t	count_dot = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '-' || str[i] == '+')) {
			continue ;
		} else if (count_dot < 1 && str[i] == '.') {
			count_dot++;
		} else if (!isdigit(str[i])) {
			return (false);
		}
	}
	double num = strtod(str.c_str(), NULL);
	double max = std::numeric_limits<double>::max();
	double min = -std::numeric_limits<double>::max();
	return (num >= min && num <= max);
}


/* Display Conversion */

void	Parser::display_conversion(void)
{
	try {
		std::cout << "char: " << _toChar() << std::endl;
		std::cout << "int: " << _toInt() << std::endl;
		std::cout << "float: " << _toFloat() << std::endl;
		std::cout << "double: " << _toDouble() << std::endl;
	} catch (const std::exception &e) {
		throw InputInvalidException();
	}
}

void	Parser::_toChar(void)
{
	switch (this->_type) {
		case (CHAR):
			if ( _inputStr[0] < std::numeric_limits<char>::min() || _inputStr[0] > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (_inputStr[0] < 32 && _inputStr[0] >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << _inputStr[0];
			}
			return ;
		case (INT):
			if (atoi(_inputStr.c_str()) < std::numeric_limits<char>::min() || atoi(_inputStr.c_str()) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (atoi(_inputStr.c_str()) < 32 && atoi(_inputStr.c_str()) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(atoi(_inputStr.c_str()));
			}
			return ;
		case (FLOAT):
			if (atof(_inputStr.c_str()) < std::numeric_limits<char>::min() || atof(_inputStr.c_str()) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (atof(_inputStr.c_str()) < 32 && atof(_inputStr.c_str()) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(atof(_inputStr.c_str()));
			}
			return ;
		case (DOUBLE):
			double d = ;
			if (strtod(_inputStr.c_str(), NULL) < std::numeric_limits<char>::min() || strtod(_inputStr.c_str(), NULL) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (strtod(_inputStr.c_str(), NULL) < 32 && strtod(_inputStr.c_str(), NULL) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(strtod(_inputStr.c_str(), NULL));
			}
			return ;
		case (PSEUDOLITERAL):
			std::cout << "impossible";
			return ;
		default:
			throw InputInvalidException();
	}
}

void	Parser::_toInt(void)
{
	switch (this->_type) {
		case (CHAR):
			std::cout << static_cast<int>(_inputStr[0]);
			return ;

		case (INT):
			std::cout << atoi(_inputStr.c_str());
			return ;

		case (FLOAT):
			if (atof(_inputStr.c_str()) < std::numeric_limits<int>::min() || atof(_inputStr.c_str()) > std::numeric_limits<int>::max()) {
				std::cout << "impossible";
			} else {
				std::cout << static_cast<int>(atof(_inputStr.c_str()));
			}
				std::cout << "impossible";
			else
				std::cout << static_cast<int>(atof(_inputStr.c_str()));
			return ;

		case (DOUBLE):
			double d = strtod(_inputStr.c_str(), NULL);
			if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
				std::cout << "impossible";
			} else {
				std::cout << static_cast<int>(d);
			}
			return ;

		case (PSEUDOLITERAL):
			std::cout << "impossible";
			return ;

		default:
			throw InputInvalidException();
	}
}

void	Parser::_toFloat(void)
{
	switch (this->_type)
	{
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_inputStr[0]) << "f";
			return ;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(atoi(_inputStr.c_str())) << "f";
			return ;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << atof(_inputStr.c_str()) << 'f';
			return ;
		case (DOUBLE):
			if (strtod(_inputStr.c_str(), NULL) < -std::numeric_limits<float>::max() || strtod(_inputStr.c_str(), NULL) > std::numeric_limits<float>::max())
				std::cout << "impossible";
			else
				std::cout << std::fixed << std::setprecision(1) << static_cast<float>(strtod(_inputStr.c_str(), NULL)) << 'f';
			return ;
		case (PSEUDOLITERAL):
			if (_inputStr == "-inff" || _inputStr == "+inff" || _inputStr == "nanf") {
				std::cout << _inputStr;
			} else {
				std::cout << _inputStr << 'f';
			}
			return ;
		default:
			throw InputInvalidException();
	}
}

void	Parser::_toDouble(void)
{
	switch (this->_type) {
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_inputStr[0]);
			return ;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atoi(_inputStr.c_str()));
			return ;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atof(_inputStr.c_str()));
			return ;
		case (DOUBLE):
			std::cout << std::fixed << std::setprecision(1) << strtod(_inputStr.c_str(), NULL);
			return ;
		case (PSEUDOLITERAL):
			if (_inputStr == "-inff" || _inputStr == "+inff" || _inputStr == "nanf") {
				std::cout << _inputStr.substr(0, _inputStr.length() - 1);
			} else {
				std::cout << _inputStr;
			}
			return ;
		default:
			throw InputInvalidException();
	}
}
