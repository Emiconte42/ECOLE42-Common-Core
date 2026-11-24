#include "Bureaucrat.hpp"
#include "utils/utils.hpp"

/*
Mots nouveaux
	try : « essaie ce bloc ». C'est le numéro risqué.
	throw : « je tombe ! ». On lance une alarme. La fonction s'arrête tout de suite.
	catch : le filet. Il attrape l'alarme et décide quoi faire (souvent : afficher le message).
	exception : l'objet alarme qui tombe. Il transporte un message, qu'on lit avec what().
*/

static void	title(std::string const &str)
{
	std::cout << BOLD_YELLOW << "\n===== " << str << " =====" << endofline;
}

int main()
{
	title("TEST 1 - normal");
	try
	{
		// le numero risque : du code qui peut lancer une alarme
		Bureaucrat bureaucrat("Bob", 40);
		Bureaucrat bureaucrat1;
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		std::cout << "bureaucrat1 : " << bureaucrat1 << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline; // le filet : on lit le message
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 2 - Grade = 1");
	try
	{
		Bureaucrat bureaucrat("Paul", 1);
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 3 - Grade = 0");
	try
	{
		Bureaucrat bureaucrat("Sam", 0);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 4 - Grade = 150");
	try
	{
		Bureaucrat bureaucrat("Henry", 150);
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 5 - Grade = 151");
	try
	{
		Bureaucrat bureaucrat("Sam", 151);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 6 - copie d'assignation");
	try
	{
		Bureaucrat bureaucrat("Jerry", 50);
		Bureaucrat bureaucrat1;
		bureaucrat1 = bureaucrat;

		std::cout << "bureaucrat : " << bureaucrat1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 7 - constructeur par copie");
	try
	{
		Bureaucrat bureaucrat("Tom", 42);
		Bureaucrat copie(bureaucrat);
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		std::cout << "copie : " << copie << std::endl;
		copie.incrementGrade();
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		std::cout << "copie : " << copie << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 8 - auto-assignation (a = a)");
	try
	{
		Bureaucrat bureaucrat("Lisa", 10);
		Bureaucrat &meme = bureaucrat;
		bureaucrat = meme;
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 9 - etat apres une exception (increment a 1)");
	{
		// declare HORS du try pour pouvoir l'afficher apres le catch
		Bureaucrat bureaucrat("Anna", 1);
		try
		{
			bureaucrat.incrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << endofline;
		}
		std::cout << "bureaucrat apres catch (attendu : grade 1) : " << bureaucrat << std::endl;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 10 - etat apres une exception (decrement a 150)");
	{
		Bureaucrat bureaucrat("Marc", 150);
		try
		{
			bureaucrat.decrementGrade();
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << endofline;
		}
		std::cout << "bureaucrat apres catch (attendu : grade 150) : " << bureaucrat << std::endl;
	}

/*--------------------------------------------------------------------------------------*/

	title("\nTEST 11 - bornes dans le bon sens (doit marcher)");
	try
	{
		Bureaucrat bureaucrat("Bas", 150);
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "bureaucrat (attendu : grade 149) : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}
	try
	{
		Bureaucrat bureaucrat("Haut", 1);
		std::cout << "bureaucrat : " << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "bureaucrat (attendu : grade 2) : " << bureaucrat << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}
	return (0);
}
