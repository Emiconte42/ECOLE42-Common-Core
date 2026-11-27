/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:30:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/05/24 11:23:19 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <iostream>
# include <string>
# include "AForm.hpp"

# define HIGHTEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);
	Bureaucrat	&operator =(const Bureaucrat &src);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	void			incrementGrade(void);
	void			decrementGrade(void);
	void			signForm(AForm &form) const;
	void			executeForm(AForm &form) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif
