#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private :
		std::string const	_name;
		int					_grade;

	public :
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat (Bureaucrat const & cpy);
		Bureaucrat & operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string			getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form) const;

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

std::ostream & operator<<(std::ostream &o, Bureaucrat const &pointGrade);

#endif