#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap	person("JOJO");
	std::string	target("VAMPIRE");

	std::cout << person << std::endl;
	for (int i = 0; i < 100; i += 1)
		person.highFivesGuys();
	std::cout << person << std::endl;
	person.highFivesGuys();
	person.attack(target);
	person.setEnergyPoints(1);
	person.attack(target);
	person.attack(target);
}
