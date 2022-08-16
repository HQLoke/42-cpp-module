#include "FragTrap.hpp"
#include "colour.h"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN;
	std::cout << "FragTrap: Blank constructor has been called\n";
	ClapTrap::setHitPoints(100);
	// ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
	std::cout << RESET;
}

/*
 * I've decided to add the scope resolution operator (::) to specify which class
 * method I'm using.
 */
FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << GREEN;
	std::cout << "FragTrap: String constructor has been called\n";
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
	std::cout << RESET;
}

/*
 * It's a good practice to call the copy constructor of the base class.
 */
FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << GREEN;
	std::cout << "FragTrap: Copy constructor has been called\n";
	std::cout << RESET;
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
	std::cout << GREEN;
	std::cout << "FragTrap: Destructor has been called\n";
	std::cout << RESET;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << GREEN;
	std::cout << "FragTrap: Copy assignment operator has been called\n";
	if ( this != &rhs )
	{
		this->ClapTrap::operator=(rhs);
	}
	std::cout << RESET;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static void	deathMessage(std::string const name)
{
	std::cout << GREEN;
	std::cout << "FragTrap " << name << " RIP...Let's fry him till he's toast!"
	<< std::endl;
	std::cout << RESET;
}

/*
 * The base-class method is shadowed by the derived class method. To use the
 * base-class method I need to use scope resolution operator (::).
 * eg: hero.ClapTrap::attack("random")
 */
void	FragTrap::attack		( const std::string & target )
{
	if (ClapTrap::getHitPoints() <= 0)
		return (deathMessage(ClapTrap::getName()));
	std::cout << GREEN;
	if (ClapTrap::getEnergyPoints() > 0)
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "FragTrap " << ClapTrap::getName() << " attacks " << target
		<< ", causing " << ClapTrap::getAttackDamage() << " points of damage!\n";
	}
	else
	{
		std::cout << "FragTrap " << ClapTrap::getName() << " has ran out of energy "
		<< "point! He can't attack anyone! Freakin' loser" << std::endl;
	}
	std::cout << RESET;
}

void	FragTrap::highFivesGuys	()
{
	if (ClapTrap::getHitPoints() <= 0)
		return (deathMessage(ClapTrap::getName()));
	std::cout << GREEN;
	if (ClapTrap::getEnergyPoints() > 0)
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "FragTrap " << ClapTrap::getName() << " is asking for a "
		<< "high five guys, anyone?" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << ClapTrap::getName() << " has ran out of energy "
		<< "point! He can't even lift his hand for a high five...he's forever alone now"
		<< std::endl;
	}
	std::cout << RESET;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
