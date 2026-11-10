#include "includes/MateriaSource.hpp"
#include "includes/Character.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "utils/utils.hpp"

/* Le sujet vient du jeu Final Fantasy VII. Une Materia est une petite boule magique.
	On la range dans l'une des poches d'un personnage, et elle lui donne un sort (Ice ou Cure). */

int main()
{
	{
		std::cout << BOLD_YELLOW << "--- Main du sujet ---" << endofline;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice()); // x5
		src->learnMateria(new Ice()); // x5
		src->learnMateria(new Ice()); // x5
		src->learnMateria(new Ice()); // x5
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}

	{
		// 4 Materias au maximum, equiper avec un inventaire plein ne fait rien
		std::cout << BOLD_YELLOW << "\n----- Inventaire plein -----" << endofline;
		Character alice("alice");
		Character bob("bob");
		AMateria* extra = new Ice();

		alice.equip(new Ice());
		alice.equip(new Cure());
		alice.equip(new Ice());
		alice.equip(new Cure());
		alice.equip(new Ice()); // 5eme equipement -> alice est full
		alice.equip(new Cure());
		alice.equip(new Ice());
		alice.equip(extra);
	
		alice.use(0, bob);
		alice.use(1, bob);
		alice.use(2, bob);
		alice.use(3, bob);
		alice.use(4, bob); // le 5eme emplacement n'existe pas
	}

	{
		// utiliser une Materia inexistante ne fait rien
		std::cout << BOLD_YELLOW << "\n----- Index invalide -----" << endofline;
		Character alice("alice");
		Character bob("bob");

		alice.equip(new Ice());
		alice.use(-1, bob);
		alice.use(1, bob);
		alice.use(2, bob);
		alice.use(10, bob);
	}

	{
		std::cout << BOLD_YELLOW << "\n----- Unequip -----" << endofline;
		Character alice("alice");
		Character bob("bob");
		AMateria* ice = new Ice();

		alice.equip(ice); // on equipe
		alice.unequip(0); // on desequipe
		alice.use(0, bob); // l'emplacement 0 est vide
		delete ice;
	}

	{
		// la copie d'un Character doit etre deep (constructeur de copie)
		std::cout << BOLD_YELLOW << "\n----- Deep copy : constructeur de copie -----" << endofline;
		Character bob("bob");
		Character* alice = new Character("alice");

		alice->equip(new Ice());
		alice->equip(new Cure());
		Character copy(*alice);
		delete alice;
		std::cout << "copy use :" << std::endl;
		copy.use(0, bob);
		copy.use(1, bob);
	}

	{
		// la copie d'un Character doit etre deep (operateur d'affectation)
		// Les anciennes Materias sont supprimees avant d'ajouter les nouvelles
		std::cout << BOLD_YELLOW << "\n----- Deep copy : operateur d'affectation -----" << endofline;
		Character bob("bob"); // detruit a la fin de }, bob est l'objet, il est sur la stack
		Character carl("carl");
		Character* alice = new Character("alice"); // sur la heap, pointeur avec adresse de l'objet, il vit tant que pas de delete...

		alice->equip(new Ice());
		carl.equip(new Cure());
		carl = *alice;
		delete alice;
		carl.use(0, bob);
	}

	{
		// createMateria() renvoie 0 si le type est inconnu
		std::cout << BOLD_YELLOW << "\n----- Type inconnu -----" << endofline;
		MateriaSource src;

		src.learnMateria(new Ice());
		src.createMateria("fire");
	}
	return (0);
}