#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"
#include "utils/utils.hpp"

int main()
{
	{
		std::cout << BOLD_YELLOW << "=== Test du sujet ===" << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << std::endl << BOLD_YELLOW << "=== WrongCat utilise comme WrongAnimal ===" << RESET << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}
	{
		std::cout << std::endl << BOLD_YELLOW << "=== WrongCat utilise comme WrongCat ===" << RESET << std::endl;
		const WrongCat* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();

		delete i;
	}
	return 0;
}