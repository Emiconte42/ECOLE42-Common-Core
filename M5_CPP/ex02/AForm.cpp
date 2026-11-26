#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "utils/utils.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSigner(150), _gradeExecuter(150)
{
	if (CALL_LOG)
		std::cout << GREEN << "AForm : Default constructor called" << endofline;
}

AForm::AForm(std::string const name, int const gradeSigner, int const gradeExecuter): _name(name), _isSigned(false), _gradeSigner(gradeSigner), _gradeExecuter(gradeExecuter)
{
	if (CALL_LOG)
		std::cout << GREEN << "AForm : Parametric constructor called" << endofline;
	if (gradeSigner > 150 || gradeExecuter > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSigner < 1 || gradeExecuter < 1)
		throw AForm::GradeTooHighException(); 
}

AForm::AForm(AForm const & cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeSigner(cpy._gradeSigner), _gradeExecuter(cpy._gradeExecuter)
{
	if (CALL_LOG)
		std::cout << GREEN << "AForm : Copy constructor called" << endofline;
}

AForm::~AForm()
{
	if (CALL_LOG)
		std::cout << BLUE << "AForm : Destructor called" << endofline;
}

std::string AForm::getName() const 
{
	return (this->_name);
}

bool AForm::getSigned() const 
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeSigner);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeExecuter);
}

AForm &AForm::operator=(AForm const &other)
{
	if (CALL_LOG)
		std::cout << "AForm : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		this->_isSigned = other.getSigned();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream &o, AForm const &AForm)
{
	o << AForm.getName() << " : " << std::endl;
	o << "  Signed           : " << (AForm.getSigned() ? "Yes" : "No") << std::endl;
	o << "  Grade to sign    : " << AForm.getGradeToSign() << std::endl;
	o << "  Grade to execute : " << AForm.getGradeToExecute();
	return (o);
}

const char *AForm::GradeTooHighException::what() const throw ()
{
	return ("AForm: grade too high");
}

const char *AForm::GradeTooLowException::what() const throw ()
{
	return ("AForm: grade too low");
}

const char *AForm::FormNotSignedException::what() const throw ()
{
	return ("AForm: Form is not signed");
}

void AForm::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() > _gradeSigner)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::execute(lexecuteur)
{
	// si le formulaire n'est pas signe
		// lancer FormNotSignedException
	// si le grade de lexecuteur est PLUS GRAND que _gradeExecuter
		// lancer GradeTooLowException
	// appeler executeAction()
}