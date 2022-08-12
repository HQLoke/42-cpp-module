#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
 * Use reference wherever you can, pointers wherever you must.
 * Avoid pointers until you can't.
 * Pointers make things harder to follow, less safe and far more dangerous.
 * Rule of thumb is to use pointers only if there is no other choice.
 * Reference must be initialized immediately, whereas pointer does not.
 */
int main(void)
{
	std::cout << "|-----------------------------------|" << std::endl;
	std::cout << "|       Test given in the PDF       |" << std::endl;
	std::cout << "|-----------------------------------|" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	std::cout << std::endl;
	std::cout << "|-----------------------------------------------|" << std::endl;
	std::cout << "|       New weapons imported from Teleria       |" << std::endl;
	std::cout << "|-----------------------------------------------|" << std::endl;
	Weapon	*dagger = new Weapon("kamish's wrath");
	Weapon	*sword = new Weapon("oathkeeper");
	
	HumanA	*primary = new HumanA("Sung Jin Woo", *dagger);
	primary->attack();
	dagger->setType("venom fang");
	primary->attack();

	HumanB	*secondary = new HumanB("Sorin Markov");
	secondary->setWeapon(*sword);
	secondary->attack();
	sword->setType("parasite blade");
	secondary->attack();

	HumanB	*extra = new HumanB("Shadow Lord");
	extra->setWeapon(*dagger);
	extra->attack();
	extra->setWeapon(*sword);
	extra->attack();
	
	std::cout << "\n[Combo attack]" << std::endl;
	primary->attack();
	secondary->attack();
	extra->attack();

	delete dagger;
	delete sword;
	delete primary;
	delete secondary;
	delete extra;
	return (0);
}
