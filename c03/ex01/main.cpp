#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	actor("JOHNNY DEPP");
	ScavTrap	actress("AMBER HEARD");

	std::cout << actor << std::endl;
	std::cout << actress << std::endl;

	actor.attack(actress.getName());
	actress.takeDamage(actor.getAttackDamage());

	std::cout << actor << std::endl;
	std::cout << actress << std::endl;

	for (int i = 0; i < 50; i += 1)
	{
		actress.attack(actor.getName());
		actor.takeDamage(actress.getAttackDamage());
	}

	actor.beRepaired(1000);
	actor.setAttackDamage(1000);
	actor.attack(actress.getName());
	actress.takeDamage(actor.getAttackDamage());

	std::cout << actor << std::endl;
	std::cout << actress << std::endl;
}
