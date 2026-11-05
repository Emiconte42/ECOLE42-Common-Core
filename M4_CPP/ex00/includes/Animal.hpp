#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected :
		std::string type;

	public :
		Animal();
		Animal(std::string const &animalType);
		Animal(Animal const &cpy);
		Animal & operator=(Animal const &other);
		virtual ~Animal();

		std::string const &getType() const;
		virtual void makeSound(void) const;
};

#endif