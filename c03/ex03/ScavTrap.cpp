#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Blank constructor has been called\n";
	// ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	// ClapTrap::setAttackDamage(20);
}

/*
 * I've decided to add the scope resolution operator (::) to specify which class
 * method I'm using.
 */
ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "ScavTrap: String constructor has been called\n";
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
}

/*
 * It's a good practice to call the copy constructor of the base class.
 */
ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap: Copy constructor has been called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

/*
 * The destructors are called in exactly the reverse order of the constructors
 * because of potential dependencies. Assume that the base-class subobject is
 * still available for use.
 */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor has been called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap: Copy assignment operator has been called\n";
	if ( this != &rhs )
	{
		this->ClapTrap::operator=(rhs);
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
 * The base-class method is shadowed by the derived class method. To use the
 * base-class method I need to use scope resolution operator (::).
 * eg: hero.ClapTrap::attack("random")
 */
void	ScavTrap::attack		( const std::string & target )
{
	std::cout << "ScavTrap " << ClapTrap::getName() 
			  << " attacks " << target
			  << ", causing " << ClapTrap::getAttackDamage() 
			  << " points of damage!\n";
}

void	ScavTrap::guardGate		()
{
	std::cout << "ScavTrap is now in Gatekeeper mode.\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
