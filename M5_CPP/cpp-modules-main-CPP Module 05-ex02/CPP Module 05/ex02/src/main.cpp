/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:16 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:25:32 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	ShrubberyCreationForm	f1 = ShrubberyCreationForm("campus");
	RobotomyRequestForm		f2 = RobotomyRequestForm("a rat");
	PresidentialPardonForm	f3 = PresidentialPardonForm("Captain Sparrow");

	thiery.executeForm(f1);
	sophie.signForm(f1);
	thiery.signForm(f1);
	sophie.executeForm(f1);
	thiery.executeForm(f1);

	lou.signForm(f2);
	lou.executeForm(f2);

	lou.signForm(f3);
	lou.executeForm(f3);

	PresidentialPardonForm	f4 = f3;
	thiery.signForm(f4);
	thiery.executeForm(f4);

	return 0;
}
