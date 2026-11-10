#include "../includes/Character.hpp"
#include "../utils/utils.hpp"

// Un character neuf doit etre propre : un nom, et un sac vide.
Character::Character() : _nameCharacter("Default")
{
	if (CALL_LOG)
		std::cout << GREEN << "Character : Default constructor called" << endofline;
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
}

// Un character neuf doit etre propre : un nom, et un sac vide.
Character::Character(std::string const &nameCharacter)
{
	if (CALL_LOG)
		std::cout << GREEN << "Character : Parametric constructor called" << endofline;
	_nameCharacter = nameCharacter;
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
}

// sac a NULL, puis operator=
Character::Character(Character const & copy)
{
	if (CALL_LOG)
		std::cout << GREEN << "Character : Copy constructor called" << endofline;
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	*this = copy;
}

// deep copy : le nom, delete les anciens sorts, clone les nouveaux
Character & Character::operator=(Character const &other)
{
	if (CALL_LOG)
		std::cout << GREEN << "Character : Copy assignment operator called" << endofline;
	if (this != &other)
	{
		_nameCharacter = other._nameCharacter;
		for (int i = 0; i < _inventorySize; i++)
		{
			if (_inventory[i])
				delete _inventory[i]; // on jette l'ancien sort
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone(); // on clone les materias de other
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

// delete les sorts restes dans le sac
Character::~Character()
{
	if (CALL_LOG)
		std::cout << RED << "Character : Destructor called" << endofline;
	for (int i = 0; i < _inventorySize; i++)
		if (_inventory[i])
			delete _inventory[i];
}

// on demande au character "comment tu t'appelles ?"
std::string const & Character::getName() const
{
	return (_nameCharacter);
}

// Le livre a fabrique un sort. Le main le donne au character. Le heros le range dans son sac.
void Character::equip(AMateria* m)
{
	if (m == NULL) // si m n'a pas de sort on return
	{
		std::cerr << BLUE << "Character : no spell to equip" << endofline;
		return;
	}
	// equiper le character avec les sorts
	for (int i = 0; i < _inventorySize; i++)
	{
		if(_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	delete m;
	std::cerr << BLUE << "Character : " << _nameCharacter << "'s inventory is full" << endofline;
}

// Le character enleve le sort de sa poche et le pose par terre. Le sort existe toujours
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cerr << BLUE << "Character : slot " << idx << " does not exist" << endofline;
		return;
	}
	if (_inventory[idx] == NULL) // si la poche est vide on fait rien
		return;
	_inventory[idx] = NULL; // sinon on la vide
}

// lance le sort de la poche idx sur target
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _inventorySize)
	{
		std::cerr << BLUE << "Character : slot " << idx << " does not exist" << endofline;
		return;
	}
	if (_inventory[idx] == NULL) // si la poche est vide... on attaque pas.
	{
		std::cerr << BLUE << "Character : slot " << idx << " is empty" << endofline;
		return;
	}
	_inventory[idx]->use(target);
}
