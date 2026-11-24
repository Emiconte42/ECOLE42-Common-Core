#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils/utils.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeSigner(150), _gradeExecuter(150)
{
	if (CALL_LOG)
		std::cout << GREEN << "Form : Default constructor called" << endofline;
}

Form::Form(std::string const name, int const gradeSigner, int const gradeExecuter): _name(name), _isSigned(false), _gradeSigner(gradeSigner), _gradeExecuter(gradeExecuter)
{
	if (CALL_LOG)
		std::cout << GREEN << "Form : Parametric constructor called" << endofline;
	if (gradeSigner > 150 || gradeExecuter > 150)
		throw Form::GradeTooLowException();
	else if (gradeSigner < 1 || gradeExecuter < 1)
		throw Form::GradeTooHighException(); 
}

Form::Form(Form const & cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeSigner(cpy._gradeSigner), _gradeExecuter(cpy._gradeExecuter)
{
	if (CALL_LOG)
		std::cout << GREEN << "Form : Copy constructor called" << endofline;
}

Form::~Form()
{
	if (CALL_LOG)
		std::cout << BLUE << "Form : Destructor called" << endofline;
}

std::string Form::getName() const 
{
	return (this->_name);
}

bool Form::getSigned() const 
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeSigner);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeExecuter);
}

Form &Form::operator=(Form const &other)
{
	if (CALL_LOG)
		std::cout << "Form : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		this->_isSigned = other.getSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream &o, Form const &form)
{
	o << form.getName() << " : " << std::endl;
	o << "  Signed           : " << (form.getSigned() ? "Yes" : "No") << std::endl;
	o << "  Grade to sign    : " << form.getGradeToSign() << std::endl;
	o << "  Grade to execute : " << form.getGradeToExecute();
	return (o);
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return ("Form: grade too high");
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return ("Form: grade too low");
}

void Form::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() > _gradeSigner)
		throw GradeTooLowException();
	else
		_isSigned = true;
}