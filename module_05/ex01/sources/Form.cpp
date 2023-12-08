/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:25:43 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/08 10:31:34 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Orthodox Canonical Class Form */

/* Constructors */
Form::Form(void) :
	_name(""), _gradeToExecute(1), _gradeToSign(1), _isSigned(false) { }

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) :
	_name(src._name), _gradeToExecute(src._gradeToExecute), _gradeToSign(src._gradeToSign), _isSigned(src._isSigned) { }

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

/* Destructor */
Form::~Form(void) { }



/* Member Functions */

/* Getters */

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool const			&Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int const			&Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const			&Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/* Exceptions */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form " << form.getName() << " is " << (form.getIsSigned() ? "" : "not ") << "signed, grade to sign is " << form.getGradeToSign() << " and grade to execute is " << form.getGradeToExecute() << std::endl;
	return (o);
}
