#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "Constructor has been called\n";
}

ClapTrap::ClapTrap( std::string const name ) 
: _hitPoints (10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor has been called\n";
	this->setName(name);
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "Copy constructor has been called\n";
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has been called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Copy assignment operator has been called\n";
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
// {
// 	// o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack		( const std::string & target )
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage	( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name << " took " << amount
			  << " points of damage!\n";
}

void	ClapTrap::beRepaired	( unsigned int amount )
{
	std::cout << "ClapTrap repairs " << amount << " points of damage!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string 	ClapTrap::getName			()	const
{
	return (this->_name);
}

int				ClapTrap::getHitPoints		()	const
{
	return (this->_hitPoints);
}

int				ClapTrap::getEnergyPoints	()	const
{
	return (this->_energyPoints);
}

int				ClapTrap::getAttackDamage	()	const
{
	return (this->_attackDamage);
}

void			ClapTrap::setName			( std::string const name )
{
	this->_name = name;
}

void			ClapTrap::setHitPoints		( int hitPoints )
{
	this->_hitPoints = hitPoints;
}

void			ClapTrap::setEnergyPoints	( int energyPoints )
{
	this->_energyPoints = energyPoints;
}

void			ClapTrap::setAttackDamage	( int attackDamage )
{
	this->_attackDamage = attackDamage;
}


/* ************************************************************************** */
