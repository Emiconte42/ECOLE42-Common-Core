#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../includes/ICharacter.hpp"
#include "../includes/AMateria.hpp"
#include <string>

/* Le vrai heros :	il a un nom et un sac de 4 Materias, et il fait ce que promet ICharacter. */

class Character : public ICharacter
{
	private:
		std::string			_nameCharacter;
		static int const	_inventorySize = 4;
		AMateria			*_inventory[_inventorySize];

	public :
		Character();
		Character(std::string const &nameCharacter);
		Character(Character const & copy);
		Character & operator=(Character const &other);

		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif