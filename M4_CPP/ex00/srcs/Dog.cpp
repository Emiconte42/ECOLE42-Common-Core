#include "../includes/Dog.hpp"
#include "../utils/utils.hpp"

Dog::Dog() : Animal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Default constructor called" << endofline;
	type = "Dog";
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy constructor called" << endofline;
}
Dog & Dog::operator=(Dog const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Dog : Copy assignment operator called" << endofline;
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	if (CALL_LOG)
		std::cout << RED << "Dog : Destructor called" << endofline;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog : ...WOUAF WOUAF..." << endofline;
}