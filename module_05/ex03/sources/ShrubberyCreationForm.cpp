/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:22:59 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 14:45:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	this->_target = src._target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try {
		checkRequirements(executor);
		std::ofstream	ofs(this->_target + "_shrubbery");
		if (!ofs.is_open())
			throw FileOpenErrorException();
		christmasTree(ofs);
		ofs.close();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &src)
{
	out << src.getName() << " is " << (src.getIsSigned() ? "" : "not ") << "signed." << std::endl;
	return (out);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
}

void	ShrubberyCreationForm::christmasTree(std::ostream &ofs) const
{
	ofs
	<< std::endl
	<< "         #" << std::endl
	<< "        ***" << std::endl
	<< "       *#*O*" << std::endl
	<< "      **O****" << std::endl
	<< "     *#**O****" << std::endl
	<< "    *O*#**O**#**" << std::endl
	<< "   *#**O*#**#****" << std::endl
	<< "  ***O*#*O****O*#*" << std::endl
	<< " **O#**O**#*O**#***" << std::endl
	<< "       | o  |" << std::endl
	<< "       |  o |" << std::endl;
}

std::string	ShrubberyCreationForm::FileOpenErrorException::what() const throw()
{
	return ("Error: FileOpenErrorException");
}

