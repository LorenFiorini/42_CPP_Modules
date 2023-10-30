/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:18:50 by lfiorini          #+#    #+#             */
/*   Updated: 2023/10/30 07:06:25 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

private:
    std::string _name;
    AMateria    *_materia[4];

public:
    Character(void);
    Character(std::string const &name);
    Character&          operator=(Character const &right);
    Character(Character const &src);
    ~Character();


    std::string const&  getName() const;
    void                equip(AMateria* materia);
    void                unequip(int idx);
    void                use(int idx, ICharacter& target);
};

#endif
