#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Blank constructor has been called\n";
	ClapTrap::setHitPoints(100);
	// ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
}

/*
 * I've decided to add the scope resolution operator (::) to specify which class
 * method I'm using.
 */
FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FragTrap: String constructor has been called\n";
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
}

/*
 * It's a good practice to call the copy constructor of the base class.
 */
FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "FragTrap: Copy constructor has been called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

/*
 * The destructors are called in exactly the reverse order of the constructors
 * because of potential dependencies. Assume that the base-class subobject is
 * still available for use.
 */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor has been called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap: Copy assignment operator has been called\n";
	if ( this != &rhs )
	{
		this->ClapTrap::operator=(rhs);
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
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
void	FragTrap::attack		( const std::string & target )
{
	std::cout << "FragTrap " << ClapTrap::getName() 
			  << " attacks " << target
			  << ", causing " << ClapTrap::getAttackDamage() 
			  << " points of damage!\n";
}

void	FragTrap::highFivesGuys	()
{
	std::cout << "Anyone up for a high five, guys?\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
