#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	action(FragTrap &frag)
{
	std::cout << " [STATS]\n";
	std::cout << "  Name: " << frag.getName() << std::endl;
	std::cout << "    HP: " << frag.getHitPoints() << std::endl;
	std::cout << "Energy: " << frag.getEnergyPoints() << std::endl;
	std::cout << "AttDmg: " << frag.getAttackDamage() << std::endl;

	std::cout << " [SKILLS]\n";
	std::cout << "1: Attack\n"; 
	std::cout << "Example: "; 
	frag.attack("FOE");
	std::cout << "2: High five\n";
	std::cout << "Example: ";
	frag.highFivesGuys();
	std::cout << "\n";
}

int main(void)
{
	FragTrap blank;			   // Blank constructor
	FragTrap frag("FRAGGER");  // String constructor
	FragTrap frag_dup1(frag);  // Copy constructor
	FragTrap frag_dup2;      
	frag_dup2 = frag;          // Copy assignment operator

	action(blank);
	action(frag);
	action(frag_dup1);
	action(frag_dup2);
}
