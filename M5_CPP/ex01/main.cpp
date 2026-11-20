#include "Bureaucrat.hpp"
#include "utils/utils.hpp"

/*
Mots nouveaux
	try : « essaie ce bloc ». C'est le numéro risqué.
	throw : « je tombe ! ». On lance une alarme. La fonction s'arrête tout de suite.
	catch : le filet. Il attrape l'alarme et décide quoi faire (souvent : afficher le message).
	exception : l'objet alarme qui tombe. Il transporte un message, qu'on lit avec what().
*/
int main()
{
	std::cout << BOLD_YELLOW << "\nTEST 1 - normal" << endofline;
	try
	{
		// le numero risque : du code qui peut lancer une alarme
		Bureaucrat robot("Bob", 40);
		std::cout << robot << std::endl;
		robot.decrementGrade();
		std::cout << robot << std::endl;
		robot.incrementGrade();
		std::cout << robot << std::endl;
		robot.incrementGrade();
		std::cout << robot << std::endl;
		robot.decrementGrade();
		std::cout << robot << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline; // le filet : on lit le message
	}

	std::cout << BOLD_YELLOW << "\nTEST 2 - Grade = 1" << endofline;
	try
	{
		Bureaucrat robot3("Paul", 1);
		std::cout << robot3 << std::endl;
		robot3.incrementGrade();
		std::cout << robot3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	std::cout << BOLD_YELLOW << "\nTEST 3 - Grade = 0" << endofline;
	try
	{
		Bureaucrat robot2("Sam", 0);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

		std::cout << BOLD_YELLOW << "\nTEST 4 - Grade = 150" << endofline;
	try
	{
		Bureaucrat robot1("Henry", 150);
		std::cout << robot1 << std::endl;
		robot1.decrementGrade();
		std::cout << robot1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}


	std::cout << BOLD_YELLOW << "\nTEST 5 - Grade = 151" << endofline;
	try
	{
		Bureaucrat robot2("Sam", 151);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}
	return (0);
}