#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

class Cat : public Animal
{
	private :
		Brain	*_brain;

	public :
		Cat();
		Cat(Cat const &cpy);
		Cat & operator=(Cat const &other);
		~Cat();

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif