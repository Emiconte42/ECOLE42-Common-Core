#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	protected :
		virtual void		executeAction() const = 0;

	private :
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSigner;
		int const			_gradeExecuter;

	public :
		AForm();
		AForm(std::string const name, int const gradeSigner, int const gradeExecuter);
		AForm (AForm const & cpy);
		AForm & operator=(AForm const &other);
		virtual ~AForm();

		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat const &bur);
		void				execute(Bureaucrat const & executor);

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual  const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public :
				virtual  const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, AForm const &pointGrade);

#endif