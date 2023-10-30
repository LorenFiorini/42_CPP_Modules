/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:20:08 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:06:36 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   _materia[4];

    public:
        MateriaSource(void);
        MateriaSource&   operator=(MateriaSource const &right);
        MateriaSource(MateriaSource const &src);
        ~MateriaSource();

        void        learnMateria(AMateria* materia);
        AMateria*   createMateria(std::string const & type);
};

#endif
