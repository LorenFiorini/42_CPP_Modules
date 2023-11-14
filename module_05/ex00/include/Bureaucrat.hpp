/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:19:37 by lfiorini          #+#    #+#             */
/*   Updated: 2023/11/14 06:25:29 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &right);

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

		// Todo: increment and decrement
		void		incrementGrade(void);
		void		decrementGrade(void);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
