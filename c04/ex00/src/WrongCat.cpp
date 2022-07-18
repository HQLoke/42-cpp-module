#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Blank constructor\n";
	WrongAnimal::setType("Cat");
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
	std::cout << "WrongCat: Copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat: Copy assignment operator\n";
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	std::cout << "My type is " << i.getType() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound()	const
{
	std::cout << "Meow~~~ Meow~~~ Meow~~~\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
