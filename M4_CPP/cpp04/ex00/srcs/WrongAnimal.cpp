#include "../includes/WrongAnimal.hpp"
#include "../utils/utils.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongAnimal : Default constructor called" << endofline;
}

WrongAnimal::WrongAnimal(std::string const &animalType) : type(animalType)
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongAnimal : Parametric constructor called" << endofline;
}
WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongAnimal : Copy constructor called" << endofline;
	*this = cpy;
}
WrongAnimal & WrongAnimal::operator=(WrongAnimal const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongAnimal : Copy assignment operator called" << endofline;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	if (CALL_LOG)
		std::cout << RED << "WrongAnimal : Destructor called" << endofline;
}

std::string const &WrongAnimal::getType() const
{
	return(this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal : ...Je suis un Wrong Animal de la foret..." << endofline;
}