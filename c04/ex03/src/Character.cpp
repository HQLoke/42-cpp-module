#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name(""), _numEquip(0)
{
	for (int i = 0; i < 4; i += 1)
		this->_materias[i] = NULL;
}

Character::Character( std::string const & name ) : _name(name), _numEquip(0)
{
	for (int i = 0; i < 4; i += 1)
		this->_materias[i] = NULL;
}

Character::Character( const Character & src )
{
	this->setName(src.getName());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			Character::equip	( AMateria *m )
{
	this->_materias[_numEquip] = m;
	this->_numEquip += 1;
}

void			Character::unequip	( int idx )
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Slot index exceeded the min/max range.\n";
		return ;
	}
	else if (idx >= _numEquip)
	{
		std::cout << "There is no materia equipped at this slot.\n";
		return ;
	}
	this->_numEquip -= 1;
}

void			Character::use		( int idx, ICharacter & target )
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Slot index exceeded the min/max range.\n";
		return ;
	}
	else if (idx >= _numEquip)
	{
		std::cout << "There is no materia equipped at this slot.\n";
		return ;
	}
	this->_materias[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const & Character::getName	() const
{
	return (this->_name);
}

void				Character::setName	( std::string name )
{
	this->_name = name;
}

/* ************************************************************************** */
