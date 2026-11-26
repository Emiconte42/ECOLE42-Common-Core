#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy) : _name(cpy._name), _grade(cpy._grade)
{
	if (CALL_LOG)
		std::cout << GREEN << "Bureaucrat : Copy constructor called" << endofline;
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
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const &bur)
{
	o << bur.getName();
	o << ", bureaucrat grade ";
	o << bur.getGrade();
	o << ".";
	return (o);
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Bureaucrat: grade too high - grade < 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Bureaucrat: grade too low - grade > 150");
}


void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = _grade - 1;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = _grade + 1;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}