#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"
#include "../utils/utils.hpp"

Dog::Dog() : Animal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Default constructor called" << endofline;
	type = "Dog";
	_brain = new Brain(); // le Dog cree son propre Brain
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy constructor called" << endofline;
	_brain = new Brain(*cpy._brain); // deep copy : nouveau Brain avec le contenu de celui de cpy
}
Dog & Dog::operator=(Dog const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy assignment operator called" << endofline;
	if (this != &other) // on protege car si a = a, on delete le Brain qu'on veut copier
	{
		delete (_brain); // l'ancien Brain existe deja : on libere sinon fuite
		_brain = new Brain(*other._brain); // deep copy, pareil que le constructeur de copie
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain; // on detruit le Brain qu'on a cree. Ordre : ~Dog -> ~Brain -> ~Animal
	if (CALL_LOG)
		std::cout << RED << "Dog : Destructor called" << endofline;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog : ...WOUAF WOUAF..." << endofline;
}

Brain *Dog::getBrain(void) const
{
	return (_brain);
}
