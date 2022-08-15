#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	hero("SUPERMAN");
	std::string	villain = "BATMAN";

	hero.attack(villain);
	hero.takeDamage(100);
	hero.attack(villain);
	hero.beRepaired(50);
	hero.takeDamage(49);
	hero.beRepaired(1);
	for (int i = 0; i < 10; i += 1)
		hero.attack(villain);
	std::cout << hero << std::endl;
}
