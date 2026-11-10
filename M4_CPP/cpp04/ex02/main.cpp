#include "includes/AAnimal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"
#include "utils/utils.hpp"

int main()
{
	{
		std::cout << BOLD_YELLOW << "----- Test sujet -----" << endofline;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		// const AAnimal* r = new AAnimal(); // ne fonctionnera pas car classe abstraite
		delete j;
		delete i;
		// delete r;
	}

	{
		std::cout << BOLD_YELLOW << "\n----- Tableau d'animaux : moitie Dog, moitie Cat -----" << endofline;
		const int NB_ANIMALS = 6;
		AAnimal	*animals[NB_ANIMALS];

		for (int i = 0; i < NB_ANIMALS; i++)
		{
			if (i % 2 == 0)
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
		// Eval : test de la deep copy
		std::cout << BOLD_YELLOW << "\n----- Dog basic / Dog tmp = basic -----" << endofline;
		Dog basic;
		{
			Dog tmp = basic;
		}
	}

	{
		// Eval : la copie doit creer un nouveau Brain et copier son contenu
		std::cout << BOLD_YELLOW << "\n----- Deep copy : constructeur de copie -----" << endofline;
		Dog a;
		a.getBrain()->setIdeas(0, "Manger");
		Dog b(a);

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

		std::cout << "a : " << a.getBrain() << " " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "b : " << b.getBrain() << " " << b.getBrain()->getIdeas(0) << std::endl;
	}
	return (0);
}