/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:53:25 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 15:02:34 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <map>

class Intern
{
	private:
		std::map<std::string, AForm *(Intern::*)(std::string)> _formMap;

		AForm	*makeShrubberyCreationForm(std::string target);
		AForm	*makeRobotomyRequestForm(std::string target);
		AForm	*makePresidentialPardonForm(std::string target);

		Intern(const Intern &src);
		Intern &operator=(const Intern &op);
	public:
		Intern(void);
		~Intern(void);

		AForm	*makeForm(std::string formName, std::string target);
};

#endif
