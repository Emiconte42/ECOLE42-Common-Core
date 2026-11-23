#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		Bureaucrat	robot("Bob", 40);
		Form		form1("Formulaire 1", 40, 30);
		std::cout << robot << std::endl;
		std::cout << form1 << std::endl;

		std::cout << form1.getSigned() << std::endl;
		form1.beSigned(robot);
		std::cout << form1.getSigned() << std::endl;
		form1.beSigned(robot);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline; // le filet : on lit le message
	}

	// std::cout << BOLD_YELLOW << "\nTEST 2 - Grade = 1" << endofline;
	// try
	// {
	// 	Bureaucrat robot3("Paul", 1);
	// 	std::cout << robot3 << std::endl;
	// 	robot3.incrementGrade();
	// 	std::cout << robot3 << std::endl;
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << RED << e.what() << endofline;
	// }

	// std::cout << BOLD_YELLOW << "\nTEST 3 - Grade = 0" << endofline;
	// try
	// {
	// 	Bureaucrat robot2("Sam", 0);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << RED << e.what() << endofline;
	// }

	// 	std::cout << BOLD_YELLOW << "\nTEST 4 - Grade = 150" << endofline;
	// try
	// {
	// 	Bureaucrat robot1("Henry", 150);
	// 	std::cout << robot1 << std::endl;
	// 	robot1.decrementGrade();
	// 	std::cout << robot1 << std::endl;
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << RED << e.what() << endofline;
	// }


	// std::cout << BOLD_YELLOW << "\nTEST 5 - Grade = 151" << endofline;
	// try
	// {
	// 	Bureaucrat robot2("Sam", 151);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << RED << e.what() << endofline;
	// }
	return (0);
}