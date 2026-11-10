#include "../includes/MateriaSource.hpp"
#include "../utils/utils.hpp"

// un livre neuf : 4 pages vides
MateriaSource::MateriaSource()
{
	if (CALL_LOG)
		std::cout << GREEN << "MateriaSource : Default constructor called" << endofline;
	for (int i = 0; i < 4; i++)
		_recipePages[i] = NULL;
}

// type ignore : livre vide
MateriaSource::MateriaSource(std::string const & type)
{
	if (CALL_LOG)
		std::cout << GREEN << "MateriaSource : Parametric constructor called" << endofline;
	(void) type;
	for (int i = 0; i < 4; i++)
		_recipePages[i] = NULL;
}

// pages a NULL, puis operator=
MateriaSource::MateriaSource(MateriaSource const &cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "MateriaSource : Copy constructor called" << endofline;
	for (int i = 0; i < 4; i++)
			_recipePages[i] = NULL;
	*this = cpy;
}

// deep copy : delete les anciennes pages, clone les nouvelles
MateriaSource & MateriaSource::operator=(MateriaSource const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "MateriaSource : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_recipePages[i])
				delete _recipePages[i]; // on jette l'ancienne recette
			if (other._recipePages[i])
				_recipePages[i] = other._recipePages[i]->clone(); // on clone les materias de other
			else
				_recipePages[i] = NULL;
		}
	}
	return (*this);
}

// delete les recettes apprises
MateriaSource::~MateriaSource()
{
	if (CALL_LOG)
		std::cout << RED << "MateriaSource : Destructor called" << endofline;
	for (int i = 0; i < 4; i++)
		if (_recipePages[i])
			delete _recipePages[i];
}

// on montre un sort au livre, il le garde en memoire sur une page
void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << BLUE << "MateriaSource : no spell to learn" << endofline;
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		if (_recipePages[i] == NULL)
		{
			_recipePages[i] = m;
			return;
		}
	}
	delete m;
	std::cerr << BLUE << "MateriaSource : the book is full" << endofline;
}

// cherche la recette par son type, renvoie un clone
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_recipePages[i] != NULL && _recipePages[i]->getType() == type)
			return (_recipePages[i]->clone());
	std::cerr << BLUE << "MateriaSource : recipe " << type << " is unknown" << endofline;
	return (0);
}