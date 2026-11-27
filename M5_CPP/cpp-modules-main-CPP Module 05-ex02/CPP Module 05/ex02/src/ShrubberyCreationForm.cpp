/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:37:06 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:26:36 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target("Untargeted")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(src._target + "_copy")
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator =(const ShrubberyCreationForm &src)
{
	(void)src;
	return *this;
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	file;
	std::string		filename = this->_target + "_shrubbery";

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
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
