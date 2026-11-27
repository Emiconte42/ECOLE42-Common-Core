/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:02:57 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:25:46 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target("Untargeted")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(src._target + "_copy")
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm	&PresidentialPardonForm::operator =(const PresidentialPardonForm &src)
{
	(void)src;
	return *this;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
