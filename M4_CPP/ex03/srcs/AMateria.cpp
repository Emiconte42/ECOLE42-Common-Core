#include "../includes/AMateria.hpp"
#include "../utils/utils.hpp"

AMateria::AMateria() : _type ("Unknown")
{
	if (CALL_LOG)
		std::cout << GREEN << "AMateria : Default constructor called" << endofline;
}

AMateria::AMateria(std::string const & type)
{
	if (CALL_LOG)
		std::cout << GREEN << "AMateria : Parametric constructor called" << endofline;
	_type = type;
}

AMateria::AMateria(AMateria const &cpy) : _type(cpy._type)
{
	if (CALL_LOG)
		std::cout << GREEN << "AMateria : Copy constructor called" << endofline;
}

AMateria & AMateria::operator=(AMateria const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "AMateria : Copy assignment operator called" << endofline;
	(void) other;
	return (*this);
}

AMateria::~AMateria()
{
	if (CALL_LOG)
		std::cout << RED << "AMateria : Destructor called" << endofline;
}

// renvoie le type : "ice", "cure"
std::string const &AMateria::getType() const
{
	return (_type);
}

// AMateria ne sait pas quel sort elle est : message par defaut
void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Hey ! I'm a virtual spell... " << std::endl; // si l'enfant n'a pas son propre use
}