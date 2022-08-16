#include "DiamondTrap.hpp"
#include "colour.h"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	std::cout << CYAN;
	std::cout << "DiamondTrap: Blank constructor has been called\n";
	this->_name = "";
	ClapTrap::setName("_clap_trap");
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	std::cout << RESET;
}

DiamondTrap::DiamondTrap( std::string const name )
{
	std::cout << CYAN;
	std::cout << "DiamondTrap: String constructor has been called\n";
	this->_name = name;
	ClapTrap::setName(name + "_clap_trap");
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	std::cout << RESET;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src)
{
	std::cout << CYAN;
	std::cout << "DiamondTrap: Copy constructor has been called\n";
	this->_name = src.DiamondTrap::getName();
	std::cout << RESET;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << CYAN;
	std::cout << "DiamondTrap: Destructor has been called\n";
	std::cout << RESET;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << CYAN;
	std::cout << "DiamondTrap: Copy assignment operator has been called\n";
	if ( this != &rhs )
	{
		this->ClapTrap::operator=(rhs);
	}
	this->_name = rhs.DiamondTrap::getName();
	std::cout << RESET;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack( const std::string & target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << CYAN;
	std::cout << "Name         : " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
	std::cout << "HitPoints    : " << ClapTrap::getHitPoints() << std::endl;
	std::cout << "EnergyPoints : " << ClapTrap::getEnergyPoints() << std::endl;
	std::cout << "AttackDamage : " << ClapTrap::getAttackDamage() << std::endl;
	std::cout << RESET;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			DiamondTrap::getName() const
{
	return (this->_name);
}

/* ************************************************************************** */
