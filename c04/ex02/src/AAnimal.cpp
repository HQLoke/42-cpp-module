#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	std::cout << "AAnimal: Default constructor\n";
	this->setType("");
}

AAnimal::AAnimal( const AAnimal & src )
{
	std::cout << "AAnimal: Copy constructor\n";
	this->setType(src.getType());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << "AAnimal: Copy assignment operator\n";
	if ( this != &rhs )
	{
		this->setType(rhs.getType());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	std::cout << "My type is " << i.getType() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound()		const
{
	std::cout << "Err...what sound does a mute Animal make?\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AAnimal::getType()	const
{
	return (this->_type);
}

void		AAnimal::setType( std::string type )
{
	this->_type = type;
}

/* ************************************************************************** */
