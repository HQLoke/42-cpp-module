#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap: Blank constructor has been called\n";
	this->_name = "";
	ClapTrap::setName("_clap_trap");
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap( std::string const name )
{
	std::cout << "DiamondTrap: String constructor has been called\n";

	this->_name = name;
	ClapTrap::setName(name + "_clap_trap");
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src)
{
	std::cout << "DiamondTrap: Copy constructor has been called\n";
	this->_name = src.DiamondTrap::getName();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor has been called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->ClapTrap::operator=(rhs);
	}
	this->_name = rhs.DiamondTrap::getName();
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack		( const std::string & target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI		()
{
	std::cout << "Name         : " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
	std::cout << "HitPoints    : " << this->_hitPoints << std::endl;
	std::cout << "EnergyPoints : " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage : " << this->_attackDamage << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			DiamondTrap::getName		()	const
{
	return (this->_name);
}

/* ************************************************************************** */
