#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils/utils.hpp"

static void	title(std::string const &str)
{
	std::cout << BOLD_YELLOW << "\n===== " << str << " =====" << endofline;
}

/* Essaie de construire un Form et affiche ce qui se passe */
static void	tryCreateForm(std::string const &name, int toSign, int toExec)
{
	std::cout << CYAN << "-> Form(\"" << name << "\", " << toSign << ", " << toExec << ")" << endofline;
	try
	{
		Form	form(name, toSign, toExec);
		std::cout << GREEN << "OK : " << endofline << form << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << "GradeTooHighException : " << e.what() << endofline;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << "GradeTooLowException : " << e.what() << endofline;
	}
}

int	main()
{
	/* ------------------------------------------------------------------ */
	title("1. Construction valide + getters + operator<<");
	{
		Form	form("A38", 50, 25);

		std::cout << form << std::endl;
		std::cout << "getName()           : " << form.getName() << std::endl;
		std::cout << "getSigned()         : " << (form.getSigned() ? "true" : "false") << std::endl;
		std::cout << "getGradeToSign()    : " << form.getGradeToSign() << std::endl;
		std::cout << "getGradeToExecute() : " << form.getGradeToExecute() << std::endl;
	}

	/* ------------------------------------------------------------------ */
	title("2. Construction avec grades limites (1 et 150) -> OK");
	tryCreateForm("Limite haute", 1, 1);
	tryCreateForm("Limite basse", 150, 150);

	/* ------------------------------------------------------------------ */
	title("3. Construction avec grades invalides -> exceptions");
	tryCreateForm("Sign trop haut", 0, 50);
	tryCreateForm("Sign trop bas", 151, 50);
	tryCreateForm("Exec trop haut", 50, 0);
	tryCreateForm("Exec trop bas", 50, 151);

	/* ------------------------------------------------------------------ */
	title("4. beSigned() appele directement");
	{
		Bureaucrat	boss("Boss", 10);
		Bureaucrat	employe("Employe", 50);
		Bureaucrat	stagiaire("Stagiaire", 150);
		Form		f1("F1", 50, 2);
		Form		f2("F2", 50, 50);
		Form		f3("F3", 50, 50);

		f1.beSigned(boss);
		std::cout << "Boss (10) signe F1 (50)  -> signed = " << f1.getSigned() << std::endl;

		f2.beSigned(employe);
		std::cout << "Employe (50) signe F2 (50)  -> signed = " << f2.getSigned() << std::endl;

		try
		{
			f3.beSigned(stagiaire);
			std::cout << RED << "ERREUR : aurait du lever une exception" << endofline;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Stagiaire (150) signe F3 (50) -> exception : " << e.what() << std::endl;
		}
		std::cout << "F3 signed = " << f3.getSigned() << " (doit rester 0)" << std::endl;
	}

	/* ------------------------------------------------------------------ */
	title("5. Bureaucrat::signForm() : reussite et echec");
	{
		Bureaucrat	alice("Alice", 1);
		Bureaucrat	bob("Bob", 149);
		Form		contrat("Contrat", 100, 100);

		bob.signForm(contrat);		// echec : 149 > 100
		std::cout << contrat << std::endl;
		alice.signForm(contrat);	// reussite
		std::cout << contrat << std::endl;
	}

	/* ------------------------------------------------------------------ */
	title("6. Signer un formulaire deja signe");
	{
		Bureaucrat	alice("Alice", 1);
		Form		form("Deja signe", 10, 10);

		alice.signForm(form);
		alice.signForm(form);
	}

	/* ------------------------------------------------------------------ */
	title("7. Forme canonique : copie et assignation");
	{
		Bureaucrat	alice("Alice", 1);
		Form		original("Original", 20, 20);

		alice.signForm(original);

		Form		copie(original);
		std::cout << "Copie    : " << copie << std::endl;

		Form		autre("Autre", 140, 140);
		autre = original;	// seul _isSigned est copie (le reste est const)
		std::cout << "Assigne  : " << autre << std::endl;
	}

	/* ------------------------------------------------------------------ */
	title("8. Attraper une exception de Form avec std::exception &");
	try
	{
		Form	bad("Bad", 200, 1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "std::exception : " << e.what() << endofline;
	}

	return (0);
}
