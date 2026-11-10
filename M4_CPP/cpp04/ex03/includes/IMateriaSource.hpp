#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

/* 	Le contrat d'un livre de sorts : il dit qu'on peut apprendre un modele et fabriquer une Materia. */

class AMateria;

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif