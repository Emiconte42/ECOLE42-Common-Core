#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &pointGrade);

#endif