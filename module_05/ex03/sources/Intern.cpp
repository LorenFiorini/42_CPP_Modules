/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:54:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 15:02:32 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	this->_formMap["shrubbery creation"] = &Intern::makeShrubberyCreationForm;
	this->_formMap["robotomy request"] = &Intern::makeRobotomyRequestForm;
	this->_formMap["presidential pardon"] = &Intern::makePresidentialPardonForm;
}

Intern::~Intern(void) { }

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::map<std::string, AForm *(Intern::*)(std::string)>::iterator it;

	it = this->_formMap.find(formName);
	if (it == this->_formMap.end())
	{
		std::cerr << "Form " << formName << " not found" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return ((this->*(it->second))(target));
}

AForm	*Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

