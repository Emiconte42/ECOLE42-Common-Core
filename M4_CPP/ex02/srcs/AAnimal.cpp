#include "../includes/AAnimal.hpp"
#include "../utils/utils.hpp"

AAnimal::AAnimal() : type("Animal")
{
	if (CALL_LOG)
		std::cout << GREEN << "Animal : Default constructor called" << endofline;
}

AAnimal::AAnimal(std::string const &animalType) : type(animalType)
{
	if (CALL_LOG)
		std::cout << GREEN << "Animal : Parametric constructor called" << endofline;
}

AAnimal::AAnimal(AAnimal const &cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Animal : Copy constructor called" << endofline;
	*this = cpy;
}

AAnimal & AAnimal::operator=(AAnimal const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Animal : Copy assignment operator called" << endofline;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	if (CALL_LOG)
		std::cout << RED << "Animal : Destructor called" << endofline;
}

std::string const &AAnimal::getType() const
{
	return(this->type);
}
