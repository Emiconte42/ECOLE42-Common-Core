#include "../includes/Ice.hpp"
#include "../utils/utils.hpp"

// type fixe : "ice"
Ice::Ice() : AMateria("ice")
{
	if (CALL_LOG)
		std::cout << GREEN << "Ice : Default constructor called" << endofline;
}

// type au choix
Ice::Ice(std::string const & type) : AMateria(type)
{
	if (CALL_LOG)
		std::cout << GREEN << "Ice : Parametric constructor called" << endofline;
}

// copie via AMateria
Ice::Ice(Ice const &cpy) : AMateria(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Ice : Copy constructor called" << endofline;
}

// operator= de AMateria
Ice & Ice::operator=(Ice const &other)
{
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	if (CALL_LOG)
		std::cout << RED << "Ice : Destructor called" << endofline;
}

// une copie neuve de ce sort
Ice* Ice::clone() const
{
	return new Ice(*this); // fabrication d'un nouvel ice grace a new, attention il faudra delete
}

// affiche l'attaque sur target
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}