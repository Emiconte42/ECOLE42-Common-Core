/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:54:24 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:27:29 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void)
	: _name("Unnamed"), _signGrade(HIGHTEST_GRADE), _execGrade(HIGHTEST_GRADE)
{
	this->_isSigned = false;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < HIGHTEST_GRADE || execGrade < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(const AForm &src)
	: _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

AForm::~AForm(void)
{

}

AForm	&AForm::operator =(const AForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src.isSigned();
	}
	return *this;
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::isSigned(void) const
{
	return this->_isSigned;
}

unsigned int	AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

unsigned int	AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

void	AForm::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	else if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	else
		this->beExecuted();
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high for his form...");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low for this form...");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("The form has not been signed.");
}

std::ostream	&operator <<(std::ostream &o, const AForm &form)
{
	o << "| AForm:\t" << form.getName() << std::endl;
	o << "|\tSigned:\t" << form.isSigned() << std::endl;
	o << "|\tGrade to sign:\t" << form.getSignGrade() << std::endl;
	o << "|\tGrade to execute:\t" << form.getExecGrade();

	return o;
}
