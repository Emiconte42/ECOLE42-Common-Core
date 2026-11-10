#ifndef ICE_HPP
#define ICE_HPP

#include "../includes/AMateria.hpp"
#include <string>

/* Le sort d'attaque : il affiche * shoots an ice bolt at bob *. */

class Ice : public AMateria
{
	public :
		Ice();
		Ice(std::string const & type);
		Ice(Ice const &cpy);
		Ice & operator=(Ice const &other);
		~Ice();

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif