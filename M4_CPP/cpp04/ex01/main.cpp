#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"
#include "utils/utils.hpp"

int main()
{
	{
		std::cout << BOLD_YELLOW << "----- Test sujet -----" << endofline;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;

		const Animal* r = new Animal();
		delete r;
	}

	{
		std::cout << BOLD_YELLOW << "\n----- Tableau d'animaux : moitie Dog, moitie Cat -----" << endofline;
		const int NB_ANIMALS = 6;
		Animal	*animals[NB_ANIMALS];

		for (int i = 0; i < NB_ANIMALS; i++)
		{
			if (i % 2 == 0) // un sur deux : pair = Dog, impair = Cat
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = 0; i < NB_ANIMALS; i++)
			animals[i]->makeSound();
		for (int i = 0; i < NB_ANIMALS; i++)
			delete animals[i];
	}

	{
		// test de la deep copy
		std::cout << std::endl << BOLD_YELLOW << "=== Test de la deep copy ===" << RESET << std::endl;
		Dog basic;
		std::cout << std::endl;
		{
			Dog tmp = basic;
		}
	}

	{
		// la copie creee un nouveau Brain et copie son contenu
		std::cout << BOLD_YELLOW << "\n----- Deep copy : constructeur de copie -----" << endofline;
		Dog a;
		a.getBrain()->setIdeas(0, "Manger");
		
		Dog b(a);
		b.getBrain()->setIdeas(0, "Boire");
		std::cout << "a : " << a.getBrain() << " " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "b : " << b.getBrain() << " " << b.getBrain()->getIdeas(0) << std::endl;
	}

	{
		// Eval : l'operateur d'affectation doit aussi faire une deep copy
		std::cout << BOLD_YELLOW << "\n----- Deep copy : operateur d'affectation -----" << endofline;
		Cat a;
		Cat b;
		a.getBrain()->setIdeas(0, "Dormir");
		b = a;
		b.getBrain()->setIdeas(0, "Ronronner");

		std::cout << "a : " << a.getBrain() << " " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "b : " << b.getBrain() << " " << b.getBrain()->getIdeas(0) << std::endl;
	}

	return (0);
}