/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:31:34 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/12 14:47:15 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		void		christmasTree(std::ostream &ofs) const;

		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const &executor) const;

		std::string	getTarget(void) const;
		void		setTarget(std::string target);

		class FileOpenErrorException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &src);

#endif

