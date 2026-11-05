#include "../includes/Brain.hpp"
#include "../utils/utils.hpp"


Brain::Brain()
{
	if (CALL_LOG)
		std::cout << GREEN << "Brain : Default constructor called" << endofline;
	for (unsigned int i = 0; i < 100; i++)
	{
		_ideas[i] = "Pas d'idee";
	}
}

Brain::Brain(Brain const &cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Brain : Copy constructor called" << endofline;
	*this = cpy;
}
Brain & Brain::operator=(Brain const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Brain : Copy assignment operator called" << endofline;
	for (unsigned int i = 0; i < 100; i++)
	{
		_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	if (CALL_LOG)
		std::cout << RED << "Brain : Destructor called" << endofline;
}

// on verifie que l'index est entre 0 et 99, sinon on sort du tableau
void Brain::setIdeas(unsigned int index, std::string const ideas)
{
	if (index < 100)
		this->_ideas[index] = ideas;
}

std::string Brain::getIdeas(unsigned int index) const
{
	if (index < 100)
		return (this->_ideas[index]);
	return ("Index invalide");
}
