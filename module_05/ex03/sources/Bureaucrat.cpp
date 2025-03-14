/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:45 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/15 00:30:53 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Orthodox Canonical Class Form */

/* 1. Default constructor */
Bureaucrat::Bureaucrat(void) :
	_name(""), _grade(150) { }

/* 2. Copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat &src) :
	_name(src._name), _grade(src._grade) { }

/* 3. Assignment operator overload */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

/* 4. Destructor */
Bureaucrat::~Bureaucrat(void) { }

/* Parameterized constructor */
Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* << Operator overload */
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (out);
}


/* Member Functions */

/* Getters */
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


/* Exceptions */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


/* Increment and decrement */
void	Bureaucrat::incrementGrade(void)
{
	try {
		if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try {
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << this->_name << "  couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
