#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_pWeapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their "
	<< _pWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_pWeapon = &weapon;
}
