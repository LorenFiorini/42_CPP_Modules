/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:18:53 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 06:47:51 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure&   operator=(Cure const &right);
        Cure(Cure const &src);
        virtual ~Cure();


        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif
