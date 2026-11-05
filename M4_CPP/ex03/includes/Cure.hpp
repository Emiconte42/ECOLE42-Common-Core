#ifndef CURE_HPP
#define CURE_HPP

#include "../includes/AMateria.hpp"
#include <string>

/* Le sort de soin : il affiche * heals bob's wounds *. */

class Cure : public AMateria
{
		public :
		Cure();
		Cure(std::string const & type);
		Cure(Cure const &cpy);
		Cure & operator=(Cure const &other);
		~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};

#endif