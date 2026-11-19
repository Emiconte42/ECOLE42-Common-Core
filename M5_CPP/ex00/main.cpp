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
//	try
//	{
//		// le numero risque : du code qui peut lancer une alarme
//	}
//	catch (std::exception & e)
//	{
//		std::cout << e.what() << std::endl; // le filet : on lit le message
//	}


	Bureaucrat robot("Bob", 40);
	Bureaucrat robot1("henry", 30);
	robot1 = robot;
	std::cout << robot << std::endl;
	std::cout << robot1 << std::endl;


	// Bureaucrat x("X", 0); // refuse : exception « note trop haute »
	// Bureaucrat y("Y", 151); // refuse : exception « note trop basse »

	// std::cout << robot.getName() << " " << robot.getGrade() << std::endl;

	// bob.incrementGrade();	// la note passe a plus haut dans la pyramide / hierarchie
	// bob.decrementGrade();	// la note passe a plus bas dans la pyramide / hierarchie

	// hello.incrementGrade(); // (chef a 1)	refuse : exception

	return (0);
}