#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"

class Dog : public AAnimal
{
	public :
		Dog();
		Dog(Dog const &cpy);
		Dog & operator=(Dog const &other);
		~Dog();

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;

		private :
		Brain	*_brain;
};

#endif