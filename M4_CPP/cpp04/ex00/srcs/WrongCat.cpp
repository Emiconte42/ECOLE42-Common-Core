#include "../includes/WrongCat.hpp"
#include "../utils/utils.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongCat : Default constructor called" << endofline;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongCat : Copy constructor called" << endofline;
}
WrongCat & WrongCat::operator=(WrongCat const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "WrongCat : Copy assignment operator called" << endofline;
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	if (CALL_LOG)
		std::cout << RED << "WrongCat : Destructor called" << endofline;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat : ...miou miou..." << endofline;
}