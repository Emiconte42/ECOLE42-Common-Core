#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

class Dog : public Animal
{
	private :
		Brain	*_brain;

	public :
		Dog();
		Dog(Dog const &cpy);
		Dog & operator=(Dog const &other);
		~Dog();

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif