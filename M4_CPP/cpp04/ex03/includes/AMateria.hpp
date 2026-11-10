#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "../includes/ICharacter.hpp"
#include <string>

/* Le livre commun des sorts : il garde le type ("ice", "cure") et oblige chaque sort a savoir se copier (clone). */

class AMateria
{
	protected :
		std::string _type;

	public :
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const &cpy);
		AMateria & operator=(AMateria const &other);
		virtual ~AMateria();

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif