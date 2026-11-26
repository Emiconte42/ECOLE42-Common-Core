#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string			_target;
		int const			_gradeSign = 145;
		int const			_gradeExec = 137;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm (ShrubberyCreationForm const & cpy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		std::string			getTarget() const;
		void				executeAction() const;
		void				createFile(std::string file);
			// std::ofstream outFile(outFilename.c_str());
};

#endif