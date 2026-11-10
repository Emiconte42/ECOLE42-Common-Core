#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "../includes/AMateria.hpp"
#include "../includes/IMateriaSource.hpp"

/* 	Le vrai livre de sorts : il garde jusqu'a 4 modeles et fabrique des copies neuves a partir d'un mot ("ice"). */

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _recipePages[4]; // les 4 pages du livre

	public:
		MateriaSource();
		MateriaSource(std::string const & type);
		MateriaSource(MateriaSource const &cpy);
		MateriaSource & operator=(MateriaSource const &other);
		~MateriaSource();
		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const & type);
};

#endif