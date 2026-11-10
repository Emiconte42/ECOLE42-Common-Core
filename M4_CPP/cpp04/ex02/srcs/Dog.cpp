#include "../includes/Dog.hpp"
#include "../utils/utils.hpp"

Dog::Dog() : AAnimal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Default constructor called" << endofline;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const &cpy) : AAnimal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy constructor called" << endofline;
	_brain = new Brain(*cpy._brain);
}
Dog & Dog::operator=(Dog const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		delete (_brain);
		_brain = new Brain(*other._brain);
		AAnimal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
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
