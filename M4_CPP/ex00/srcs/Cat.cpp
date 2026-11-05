#include "../includes/Cat.hpp"
#include "../utils/utils.hpp"

Cat::Cat() : Animal()
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Default constructor called" << endofline;
	type = "Cat";
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy constructor called" << endofline;
}
Cat & Cat::operator=(Cat const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Cat : Copy assignment operator called" << endofline;
	Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	if (CALL_LOG)
		std::cout << RED << "Cat : Destructor called" << endofline;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat : ...MIAOUUUUUU..." << endofline;
}