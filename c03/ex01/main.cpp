#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	action(ScavTrap &scav)
{
	std::cout << " [STATS]\n";
	std::cout << "  Name: " << scav.getName() << std::endl;
	std::cout << "    HP: " << scav.getHitPoints() << std::endl;
	std::cout << "Energy: " << scav.getEnergyPoints() << std::endl;
	std::cout << "AttDmg: " << scav.getAttackDamage() << std::endl;

	std::cout << " [SKILLS]\n";
	std::cout << "1: Attack\n"; 
	std::cout << "Example: "; 
	scav.attack("FOE");
	std::cout << "2: Guard gate\n";
	std::cout << "Example: ";
	scav.guardGate();
	std::cout << "\n";
}

int main(void)
{
	ScavTrap blank;			   // Blank constructor
	ScavTrap scav("GUARDIAN"); // String constructor
	ScavTrap scav_dup1(scav);  // Copy constructor
	ScavTrap scav_dup2;      
	scav_dup2 = scav;          // Copy assignment operator

	action(blank);
	action(scav);
	action(scav_dup1);
	action(scav_dup2);
}
