#include "../includes/Cure.hpp"
#include "../utils/utils.hpp"

// type fixe : "cure"
Cure::Cure() : AMateria("cure")
{
	if (CALL_LOG)
		std::cout << GREEN << "Cure : Default constructor called" << endofline;
}

// type au choix
Cure::Cure(std::string const & type) : AMateria(type)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cure : Parametric constructor called" << endofline;
}

// copie via AMateria
Cure::Cure(Cure const &cpy) : AMateria(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cure : Copy constructor called" << endofline;
}
// operator= de AMateria
Cure & Cure::operator=(Cure const &other)
{
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	if (CALL_LOG)
		std::cout << RED << "Cure : Destructor called" << endofline;
}

// une copie neuve de ce sort
Cure* Cure::clone() const
{
	return new Cure(*this); // fabrication d'un nouveau Cure grace a new, attention il faudra delete
}

// affiche le soin sur target
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}