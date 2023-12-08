/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:25:49 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/08 10:30:48 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:
		std::string const	_name;
		int	const			_gradeToExecute;
		int	const			_gradeToSign;
		bool				_isSigned;

	public:
		Form(void);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(const Form &copy);
		Form &operator=(const Form &op);
		~Form(void);

		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExecute(void) const;

		void	beSigned(Bureaucrat const &bureaucrat);

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

};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
