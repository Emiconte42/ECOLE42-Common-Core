#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string				_target;
		static int const		_gradeSign = 145;
		static int const		_gradeExec = 137;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm (ShrubberyCreationForm const & cpy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		std::string				getTarget() const;

	protected :
		void			executeAction(void) const;
		// void					createFile() const;
};

#endif