/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:25:43 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 14:32:48 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Orthodox Canonical Class AForm */

/* Constructors */
AForm::AForm(void) :
	_name(""), _gradeToExecute(1), _gradeToSign(1), _isSigned(false) { }

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) :
	_name(src._name), _gradeToExecute(src._gradeToExecute), _gradeToSign(src._gradeToSign), _isSigned(src._isSigned) { }

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

/* Destructor */
AForm::~AForm(void) { }


/* Member Functions */

/* Getters */

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

bool const			&AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int const			&AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const			&AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/* Exceptions */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::checkRequirements(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	if (!this->_isSigned)
		throw UnsignedFormException();
}

std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	o << "AForm " << form.getName() << std::endl;
	if (form.getIsSigned())
		o << " Status: signed" << std::endl;
	else
		o << " Status: not signed" << std::endl;
	o << " Grade to sign: " << form.getGradeToSign() << std::endl;
	o << " Grade to execute: " << form.getGradeToExecute() << std::endl;
	return (o);
}
