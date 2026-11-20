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
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
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
		std::cout << BLUE << "Bureaucrat : Destructor called" << endofline;
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

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Bureaucrat: grade too high - grade > 150");
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Bureaucrat: grade too low - grade < 1");
}

void Bureaucrat::incrementGrade()
{
	_grade = _grade - 1;
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
	_grade = _grade + 1;
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}