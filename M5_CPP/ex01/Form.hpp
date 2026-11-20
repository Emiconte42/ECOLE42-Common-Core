#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
// #include <exception>

class Form
{
	private :
		std::string const	_name;
		bool				_isSigned;
		int					_grade;

	public :
		Form(); // constructeur par defaut
		// Bureaucrat(std::string const name, int grade); // constructeur par defaut avec name et grade
		Form (Form const & cpy); // constructeur par copie
		Form & operator=(Form const &other); // operateur d'assignation
		~Form(); // destructeur

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void beSigned(const Bureaucrat bur); // prends un bureaucrat en parametre

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