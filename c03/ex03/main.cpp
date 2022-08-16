#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap	a("CAPTAIN AMERICA");
	FragTrap	b("IRON MAN");
	ScavTrap	c("THOR");
	DiamondTrap z("HULK");

	z.whoAmI();

	a.attack(z.getName());
	z.takeDamage(a.getAttackDamage());
	b.attack(z.getName());
	z.takeDamage(b.getAttackDamage());
	c.attack(z.getName());
	z.takeDamage(c.getAttackDamage());
	
	z.whoAmI();

	a.attack(z.getName());
	z.takeDamage(a.getAttackDamage());
	b.attack(z.getName());
	z.takeDamage(b.getAttackDamage());
	c.attack(z.getName());
	z.takeDamage(c.getAttackDamage());

	z.whoAmI();

	z.attack(a.getName());
	z.beRepaired(1);
	z.setAttackDamage(5000);

	/*
	 * Get name from the DiamondTrap class instead of the ClapTrap class
	 */
	std::cout << z.getName() << std::endl;

	z.attack(a.getName());
	a.takeDamage(z.getAttackDamage());
	z.attack(b.getName());
	b.takeDamage(z.getAttackDamage());
	z.attack(c.getName());
	c.takeDamage(z.getAttackDamage());
	
	return (0);
}
