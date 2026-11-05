#include "../includes/Cat.hpp"
#include "../utils/utils.hpp"

Cat::Cat() : AAnimal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Default constructor called" << endofline;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &cpy) : AAnimal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy constructor called" << endofline;
	_brain = new Brain(*cpy._brain);
}
Cat & Cat::operator=(Cat const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		delete (_brain);
		_brain = new Brain(*other._brain);
		AAnimal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
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
