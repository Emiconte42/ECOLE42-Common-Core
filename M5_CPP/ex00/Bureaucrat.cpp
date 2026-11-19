#include "Bureaucrat.hpp"
#include "utils/utils.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	if (CALL_LOG)
		std::cout << GREEN << "Bureaucrat : Default constructor called" << endofline;
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
	o << ".";
	return (o); // retourne le flux
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name) : _messageHigh(name + "'s grade too high")
{
	if (CALL_LOG)
		std::cout << GREEN << "GradeTooHighException : Default constructor called" << endofline;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{
	if (CALL_LOG)
		std::cout << RED << "GradeTooHighException : Destructor called" << endofline;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name) : _messageLow(name + "'s grade too low")
{
	if (CALL_LOG)
		std::cout << GREEN << "GradeTooLowException : Default constructor called" << endofline;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{
	if (CALL_LOG)
		std::cout << RED << "GradeTooLowException : Destructor called" << endofline;
}

const char *Bureaucrat::GradeTooHighException::what() const throw () 
{
	return (_messageHigh.c_str());
}

const char *Bureaucrat::GradeTooLowException::what() const throw () 
{
	return (_messageLow.c_str());
}