/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:40:51 by ocartier          #+#    #+#             */
/*   Updated: 2022/06/14 12:33:02 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

	virtual void	beExecuted(void) const = 0;

public:
	AForm(void);
	AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
	AForm(const AForm &src);
	virtual ~AForm(void);
	AForm	&operator =(const AForm &src);

	std::string		getName(void) const;
	bool			isSigned(void) const;
	unsigned int	getSignGrade(void) const;
	unsigned int	getExecGrade(void) const;

	void			beSigned(const Bureaucrat bur);
	void			execute(const Bureaucrat &executor) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class FormNotSignedException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream	&operator <<(std::ostream &o, const AForm &form);

#endif
