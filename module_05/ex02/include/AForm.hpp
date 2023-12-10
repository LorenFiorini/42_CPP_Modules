/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:25:49 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/10 17:45:56 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		int	const			_gradeToExecute;
		int	const			_gradeToSign;
		bool				_isSigned;

		AForm(void);
		AForm &operator=(const AForm &rhs);

	protected:
		void	checkRequirements(Bureaucrat const &bureaucrat) const;

	public:
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		// Member functions
		void	beSigned(Bureaucrat const &bureaucrat);

		// Pure virtual functions
		virtual void	execute(Bureaucrat const &executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class UnsignedFormException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, const AForm &form);

#endif
