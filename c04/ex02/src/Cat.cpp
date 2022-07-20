#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat: Default constructor\n";
	AAnimal::setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src ) : AAnimal(src)
{
	std::cout << "Cat: Copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat: Destructor\n";
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat: Copy assignment operator\n";
	if ( this != &rhs )
	{
		this->_brain = rhs._brain;
		this->_type = rhs._type;
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

Brain* 	Cat::getBrain()		const
{
	return (this->_brain);
}

/* ************************************************************************** */
