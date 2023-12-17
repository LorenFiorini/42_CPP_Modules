/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:31:34 by lfiorini          #+#    #+#             */
/*   Updated: 2023/12/15 00:49:50 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		void		christmasTree(std::ostream &ofs) const;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
		~ShrubberyCreationForm(void);

		virtual void	execute(Bureaucrat const &executor) const;

		std::string	getTarget(void) const;

};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &src);

#endif

