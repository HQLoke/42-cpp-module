#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	hero("MARIO");
	std::string	enemy("BOWSER");

	hero.setAttackDamage(3);
	hero.attack(enemy);
	hero.takeDamage(2);
	hero.beRepaired(4);
}
