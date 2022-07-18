#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat: Blank constructor\n";
	Animal::setType("Cat");
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	std::cout << "Cat: Copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat: Copy assignment operator\n";
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound()	const
{
	std::cout << "Meow~~~ Meow~~~ Meow~~~\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
