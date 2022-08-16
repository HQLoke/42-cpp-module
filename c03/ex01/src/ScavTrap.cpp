#include "ScavTrap.hpp"
#include "colour.h"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << YELLOW;
	std::cout << "ScavTrap: Blank constructor has been called\n";
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
	std::cout << RESET;
}

/*
 * I've decided to add the scope resolution operator (::) to specify which class
 * method I'm using.
 */
ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << YELLOW;
	std::cout << "ScavTrap: String constructor has been called\n";
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
	std::cout << RESET;
}

/*
 * It's a good practice to call the copy constructor of the base class.
 */
ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << YELLOW;
	std::cout << "ScavTrap: Copy constructor has been called\n";
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
ScavTrap::~ScavTrap()
{
	std::cout << YELLOW;
	std::cout << "ScavTrap: Destructor has been called\n";
	std::cout << RESET;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << YELLOW;
	std::cout << "ScavTrap: Copy assignment operator has been called\n";
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
	std::cout << YELLOW;
	std::cout << "ScavTrap " << name << " RIP...Let's slap him till he wakes up!"
	<< std::endl;
	std::cout << RESET;
}

/*
 * The base-class method is shadowed by the derived class method. To use the
 * base-class method I need to use scope resolution operator (::).
 * eg: hero.ClapTrap::attack("random")
 */
void	ScavTrap::attack( const std::string & target )
{
	if (ClapTrap::getHitPoints() <= 0)
		return (deathMessage(ClapTrap::getName()));
	std::cout << YELLOW;
	if (ClapTrap::getEnergyPoints() > 0)
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "ScavTrap " << ClapTrap::getName() << " attacks " << target
		<< ", causing " << ClapTrap::getAttackDamage() << " points of damage!\n";
	}
	else
	{
		std::cout << "ScavTrap " << ClapTrap::getName() << " has ran out of energy "
		<< "point! He can't attack anyone! Just a lump of meat now" << std::endl;
	}
	std::cout << RESET;
}

void	ScavTrap::guardGate()
{
	if (ClapTrap::getHitPoints() <= 0)
		return (deathMessage(ClapTrap::getName()));
	std::cout << YELLOW;
	if (ClapTrap::getEnergyPoints() > 0)
	{
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
		std::cout << "ScavTrap " << ClapTrap::getName() << " is now in Gatekeeper "
		<< "mode. What a baby!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << ClapTrap::getName() << " has ran out of energy "
		<< "point! He can't defend himself! Just throw him into the bin" << std::endl;
	}
	std::cout << RESET;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
