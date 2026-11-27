/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:40:38 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:26:08 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target("Untargeted")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(src._target + "_copy")
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator =(const RobotomyRequestForm &src)
{
	(void)src;
	return *this;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::srand(std::time(0));
	int rand = 1 + std::rand()/((RAND_MAX + 1u)/2); // [1, 2]
	if (rand == 1)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "Oops... The robotomization has failed for " << this->_target << "." << std::endl;
}
