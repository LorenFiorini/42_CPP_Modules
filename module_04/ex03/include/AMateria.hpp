/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:18:47 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 06:46:14 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria& operator=(AMateria const &src);
        AMateria(AMateria const &src);
        virtual ~AMateria();
    
        std::string const & getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};

#endif
