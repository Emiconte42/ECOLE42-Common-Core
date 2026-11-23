#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private :
		std::string const	_name;
		int					_grade;

	public :
		Bureaucrat(); // constructeur par defaut
		Bureaucrat(std::string const name, int grade); // constructeur par defaut avec name et grade
		Bureaucrat (Bureaucrat const & cpy); // constructeur par copie
		Bureaucrat & operator=(Bureaucrat const &other); // operateur d'assignation
		~Bureaucrat(); // destructeur

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(Form form) const;

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