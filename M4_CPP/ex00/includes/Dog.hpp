#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(Dog const &cpy);
		Dog & operator=(Dog const &other);
		~Dog();

		virtual void makeSound(void) const;
};

#endif