#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource() : _numMateria(0)
{
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		(void)rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria	*MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i += 1)
	{
		if (this->_learnedMateria[i]->getType() == type)
			return (this->_learnedMateria[i]->clone());
	}
	std::cout << "Materia type <" << type << "> not found\n";
	return (NULL);
}

void		MateriaSource::learnMateria( AMateria *mat )
{
	if (this->_numMateria > 4)
	{
		std::cout << "Slot full. Cannot learn new Materia.\n";
		return ;
	}
	this->_learnedMateria[this->_numMateria] = mat;
	this->_numMateria += 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
