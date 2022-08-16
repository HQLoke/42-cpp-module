#include "ClapTrap.hpp"
#include "colour.h"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << RED;
	std::cout << "ClapTrap: Blank constructor has been called" << std::endl;
	this->_name = "";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << RESET;
}

ClapTrap::ClapTrap( std::string const name ) 
{
	std::cout << RED;
	std::cout << "ClapTrap: String constructor has been called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << RESET;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << RED;
	std::cout << "ClapTrap: Copy constructor has been called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << RESET;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << RED;
	std::cout << "ClapTrap: Destructor has been called" << std::endl;
	std::cout << RESET;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &			ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << RED;
	std::cout << "ClapTrap: Copy assignment operator has been called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << RESET;
	return *this;
}

std::ostream &		operator<<( std::ostream & o, ClapTrap const & i )
{
	std::cout << RED;
	o << "[Stats]\n" 
	  << "Name  : " << i.getName() << "\n"
	  << "HP    : " << i.getHitPoints() << "\n"
	  << "EP    : " << i.getEnergyPoints() << "\n"
	  << "AttDmg: " << i.getAttackDamage();
	std::cout << RESET;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static void	deathMessage(std::string const name)
{
	std::cout << RED;
	std::cout << "ClapTrap " << name << " RIP...Stop bothering him!" << std::endl;
	std::cout << RESET;
}

void	ClapTrap::attack( const std::string & target )
{
	if (this->_hitPoints <= 0)
		return (deathMessage(this->_name));
	std::cout << RED;
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy point left"
		<< "...Everyone, let's start clapping for this useless bastard!" 
		<< std::endl;
	}
	std::cout << RESET;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0)
		return (deathMessage(this->_name));
	std::cout << RED;
	std::cout << "ClapTrap " << this->_name << " took " << amount
	<< " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " has been defeated! "
		<< "Bye bye loser!" << std::endl;
	}
	std::cout << RESET;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << RED;
	this->_hitPoints += amount;
	std::cout << "ClapTrap repairs " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints == (int)amount)
	{
		std::cout << "ClapTrap " << this->_name << " is back from the dead!"
		<< std::endl;
	}
	std::cout << RESET;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int			ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int			ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int			ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void		ClapTrap::setName	( std::string name )
{
	this->_name = name;
}

void		ClapTrap::setHitPoints	( unsigned int amount )
{
	this->_hitPoints = amount;
}

void		ClapTrap::setEnergyPoints ( unsigned int amount )
{
	this->_energyPoints = amount;
}

void		ClapTrap::setAttackDamage ( unsigned int amount )
{
	this->_attackDamage = amount;
}


/* ************************************************************************** */
