#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("")
{
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
}

AMateria::AMateria( const AMateria & src )
{
	this->setType(src.getType());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		AMateria::getType() const
{
	return (this->_type);
}

void					AMateria::setType( std::string type )
{
	this->_type = type;
}

/* ************************************************************************** */
