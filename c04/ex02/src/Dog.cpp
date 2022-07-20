#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog: Default constructor\n";
	AAnimal::setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src ) : AAnimal(src)
{
	std::cout << "Dog: Copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog: Destructor\n";
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog: Copy assignment operator\n";
	if ( this != &rhs )
	{
		this->_brain = rhs._brain;
		this->_type = rhs._type;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Dog const & i )
// {

// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound()	const
{
	std::cout << "Woof!!! Woof!!! Woof!!!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain* 	Dog::getBrain()		const
{
	return (this->_brain);
}

/* ************************************************************************** */
