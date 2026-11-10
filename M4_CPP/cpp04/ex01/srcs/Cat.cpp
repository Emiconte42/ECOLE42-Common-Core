#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"
#include "../utils/utils.hpp"

Cat::Cat() : Animal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Default constructor called" << endofline;
	type = "Cat";
	_brain = new Brain(); // le Cat cree son propre Brain
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy constructor called" << endofline;
	_brain = new Brain(*cpy._brain); // deep copy : nouveau Brain avec le contenu de celui de cpy
}
Cat & Cat::operator=(Cat const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy assignment operator called" << endofline;
	if (this != &other) // on protege car si a = a, on delete le Brain qu'on veut copier
	{
		delete (_brain); // l'ancien Brain existe deja : on libere sinon fuite
		_brain = new Brain(*other._brain); // deep copy, pareil que le constructeur de copie
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain; // on detruit le Brain qu'on a cree. Ordre : ~Cat -> ~Brain -> ~Animal
	if (CALL_LOG)
		std::cout << RED << "Cat : Destructor called" << endofline;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat : ...MIAOUUUUUU..." << endofline;
}

Brain *Cat::getBrain(void) const
{
	return (_brain);
}
