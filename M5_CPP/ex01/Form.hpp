#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private :
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSigner;
		int const			_gradeExecuter;

	public :
		Form();
		Form(std::string const name, int const gradeSigner, int const gradeExecuter);
		Form (Form const & cpy);
		Form & operator=(Form const &other);
		~Form();

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(Bureaucrat const &bur); // beSigned reçoit une reference vers un Bureaucrat constant, et ne renvoie rien

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
};

std::ostream & operator<<(std::ostream &o, Form const &pointGrade);

#endif