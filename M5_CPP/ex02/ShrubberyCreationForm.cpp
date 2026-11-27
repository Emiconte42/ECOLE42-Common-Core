#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "utils/utils.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", _gradeSign, _gradeExec), _target("Untargeted")
{ 
	if (CALL_LOG)
		std::cout << GREEN << "---- ShrubberyCreationForm : Default constructor called" << endofline;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation", _gradeSign, _gradeExec), _target(target)
{
	if (CALL_LOG)
		std::cout << GREEN << "---- ShrubberyCreationForm : Parametric constructor called" << endofline;
	// if (gradeSigner > 150 || gradeExecuter > 150)
// 		throw AForm::GradeTooLowException();
// 	else if (gradeSigner < 1 || gradeExecuter < 1)
// 		throw AForm::GradeTooHighException(); 
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy) : AForm(cpy)
{
	if (CALL_LOG)
		std::cout << GREEN << "---- ShrubberyCreationForm : Copy constructor called" << endofline;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (CALL_LOG)
		std::cout << BLUE << "---- ShrubberyCreationForm : Destructor called" << endofline;
}

std::string ShrubberyCreationForm::getTarget() const 
{
	return (this->_target);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (CALL_LOG)
		std::cout << "---- ShrubberyCreationForm : Copy assignment operator called" << endofline;
	(void) other;
	return (*this);
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file;
	std::string		filename = this->_target + "_shrubbery";

	// file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.open(filename.c_str());
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file.close();
}
