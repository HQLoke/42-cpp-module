#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Animal: Blank constructor\n";
	this->setType("");
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal: Copy constructor\n";
	this->setType(src.getType());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal: Copy assignment operator\n";
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	std::cout << "My type is " << i.getType() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound()		const
{
	std::cout << "Err...what sound does a mute animal make?\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType()	const
{
	return (this->_type);
}

void		Animal::setType( std::string type )
{
	this->_type = type;
}

/* ************************************************************************** */
