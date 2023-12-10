/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/10 18:20:53 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &right);
	public:
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;

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

		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(AForm &form) const;
		void		executeForm(AForm const &form) const;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
