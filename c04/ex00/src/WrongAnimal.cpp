#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Blank constructor\n";
	this->setType("");
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "WrongAnimal: Copy constructor\n";
	this->setType(src.getType());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal: Copy assignment operator\n";
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	std::cout << "My type is " << i.getType() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongAnimal::makeSound()		const
{
	std::cout << "Err...what sound does a mute animal make?\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongAnimal::getType()	const
{
	return (this->_type);
}

void		WrongAnimal::setType( std::string type )
{
	this->_type = type;
}


/* ************************************************************************** */
