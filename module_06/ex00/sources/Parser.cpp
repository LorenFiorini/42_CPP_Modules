/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:35:55 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/18 02:56:53 by lfiorini         ###   ########.fr       */
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

std::string Parser::_input = "";
eType		Parser::_type = OTHER;


/* Exceptions */
const char *Parser::InvalidInputException::what() const throw() {
	return ("InvalidInputException: the string is invalid for conversion");
}


/* Parse Input String */

void	Parser::parse_input(std::string &str)
{
	try {
		setInput(str);
		setType(_input);
	} catch (const std::exception &e) {
		throw InvalidInputException();
	}
}

void	Parser::setInput(std::string str)
{
	if (str.length() == 0) {
		throw InvalidInputException();
	}
	std::string	white_spaces = " \t\n\v\f\r";
	size_t		start	= str.find_first_not_of(white_spaces);
	size_t		end		= str.find_last_not_of(white_spaces);

	if (start != std::string::npos && end != std::string::npos) {
		_input = str.substr(start, end - start + 1);
	}
}

void	Parser::setType(std::string str)
{
	if (_isChar(str)) {
		_type = CHAR;
	} else if (_isInt(str)) {
		_type = INT;
	} else if (_isFloat(str)) {
		_type = FLOAT;
	} else if (_isDouble(str)) {
		_type = DOUBLE;
	} else if (_isPseudoLiteral(str)) {
		_type = PSEUDOLITERAL;
	} else {
		throw InvalidInputException();
	}
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
	for (size_t i = 0; i < str.length(); i++) {
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

bool	Parser::_isPseudoLiteral(std::string str) {
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan") {
		return (true);
	}
	return (false);
}

/* Display Conversion */

void	Parser::display_conversion(void)
{
	try {
		_toChar();
		_toInt();
		_toFloat();
		_toDouble();
	} catch (const std::exception &e) {
		throw InvalidInputException();
	}
}

void	Parser::_toChar(void)
{
	std::cout << "char: ";
	switch (_type) {
		case (CHAR):
			if ( _input[0] < std::numeric_limits<char>::min() || _input[0] > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (_input[0] < 32 && _input[0] >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << _input[0];
			}
			break ;
		case (INT):
			if (atoi(_input.c_str()) < std::numeric_limits<char>::min() || atoi(_input.c_str()) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (atoi(_input.c_str()) < 32 && atoi(_input.c_str()) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(atoi(_input.c_str()));
			}
			break ;
		case (FLOAT):
			if (atof(_input.c_str()) < std::numeric_limits<char>::min() || atof(_input.c_str()) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (atof(_input.c_str()) < 32 && atof(_input.c_str()) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(atof(_input.c_str()));
			}
			break ;
		case (DOUBLE):
			if (strtod(_input.c_str(), NULL) < std::numeric_limits<char>::min() || strtod(_input.c_str(), NULL) > std::numeric_limits<char>::max()) {
				std::cout << "impossible";
			} else if (strtod(_input.c_str(), NULL) < 32 && strtod(_input.c_str(), NULL) >= std::numeric_limits<char>::min()) {
				std::cout << "Non displayable";
			} else {
				std::cout << static_cast<char>(strtod(_input.c_str(), NULL));
			}
			break ;
		case (PSEUDOLITERAL):
			std::cout << "impossible";
			break ;
		default:
			throw InvalidInputException();
	}
	std::cout << std::endl;
}

void	Parser::_toInt(void)
{
	std::cout << "int: ";
	switch (_type) {
		case (CHAR):
			std::cout << static_cast<int>(_input[0]);
			break ;
		case (INT):
			std::cout << atoi(_input.c_str());
			break ;
		case (FLOAT):
			if (atof(_input.c_str()) < std::numeric_limits<int>::min() || atof(_input.c_str()) > std::numeric_limits<int>::max()) {
				std::cout << "impossible";
			} else {
				std::cout << static_cast<int>(atof(_input.c_str()));
			}
			break ;
		case (DOUBLE):
			if (strtod(_input.c_str(), NULL) < std::numeric_limits<int>::min() || strtod(_input.c_str(), NULL) > std::numeric_limits<int>::max()) {
				std::cout << "impossible";
			} else {
				std::cout << static_cast<int>(strtod(_input.c_str(), NULL));
			}
			break ;
		case (PSEUDOLITERAL):
			std::cout << "impossible";
			break ;
		default:
			throw InvalidInputException();
	}
	std::cout << std::endl;
}

void	Parser::_toFloat(void)
{
	std::cout << "float: ";
	switch (_type)
	{
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_input[0]) << "f";
			break ;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(atoi(_input.c_str())) << "f";
			break ;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << atof(_input.c_str()) << 'f';
			break ;
		case (DOUBLE):
			if (strtod(_input.c_str(), NULL) < -std::numeric_limits<float>::max() || strtod(_input.c_str(), NULL) > std::numeric_limits<float>::max())
				std::cout << "impossible";
			else
				std::cout << std::fixed << std::setprecision(1) << static_cast<float>(strtod(_input.c_str(), NULL)) << 'f';
			break ;
		case (PSEUDOLITERAL):
			if (_input == "-inff" || _input == "+inff" || _input == "nanf") {
				std::cout << _input;
			} else {
				std::cout << _input << 'f';
			}
			break ;
		default:
			throw InvalidInputException();
	}
	std::cout << std::endl;
}

void	Parser::_toDouble(void)
{
	std::cout << "double: ";
	switch (_type) {
		case (CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_input[0]);
			break ;
		case (INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atoi(_input.c_str()));
			break ;
		case (FLOAT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(atof(_input.c_str()));
			break ;
		case (DOUBLE):
			std::cout << std::fixed << std::setprecision(1) << strtod(_input.c_str(), NULL);
			break ;
		case (PSEUDOLITERAL):
			if (_input == "-inff" || _input == "+inff" || _input == "nanf") {
				std::cout << _input.substr(0, _input.length() - 1);
			} else {
				std::cout << _input;
			}
			break ;
		default:
			throw InvalidInputException();
	}
	std::cout << std::endl;
}
