#include "Bureaucrat.hpp"
#include "utils/utils.hpp"

Bureaucrat::Bureaucrat() : _name()
{
	if (CALL_LOG)
		std::cout << GREEN << "Bureaucrat : Default constructor called" << endofline;
	// _name = "Default";
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	if (CALL_LOG)
		std::cout << GREEN << "Bureaucrat : Parametric constructor called" << endofline;
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Bureaucrat : Copy constructor called" << endofline;
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{
	if (CALL_LOG)
		std::cout << RED << "Bureaucrat : Destructor called" << endofline;
}

std::string Bureaucrat::getName() const 
{
	return (this->_name);
}

int Bureaucrat::getGrade() const 
{
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (CALL_LOG)
		std::cout << "Bureaucrat : Copy assignment operator called" << endofline;
	if (this != &other) // protection : evite de se copier sur soi-meme (a = a)
	{
		this->_grade = other.getGrade();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const &bur)
{
	o << bur.getName(); // met le resultat dans le flux
	o << ", bureaucrat grade ";
	o << bur.getGrade();
	return (o); // retourne le flux
}