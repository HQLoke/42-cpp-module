#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _rWeapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
	<< this->_rWeapon.getType() << std::endl;
}
