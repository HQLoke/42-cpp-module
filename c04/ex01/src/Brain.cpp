#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain: Default constructor\n";
	for (size_t i = 0; i < 100; i += 1)
		this->_ideas[i] = "stuff";
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain: Copy constructor\n";
	for (size_t i = 0; i < 100; i += 1)
		this->_ideas[i] = src._ideas[i];
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain: Destructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain: Copy assignment operator\n";
	if ( this != &rhs )
	{
		for (size_t i = 0; i < 100; i += 1)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Brain const & i )
// {
	
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Brain::printIdeas(void) const
{
	for (size_t i = 0; i < 100; i += 1)
		std::cout << this->_ideas[i] << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Brain::setIdeas(std::string idea)
{
	for (size_t i = 0; i < 100; i += 1)
		this->_ideas[i] = idea;
}

/* ************************************************************************** */
