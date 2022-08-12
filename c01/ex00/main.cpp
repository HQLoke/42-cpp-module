#include "Zombie.hpp"
#include "colour.h"

/*
 * This exercise is about understanding heap vs stack memory.
 * The randomChump function is placed before delete to see how constructor and
 * destructor are called.
 */
int main(void)
{
	std::cout << "|-------------------------|" << std::endl;
	std::cout << "|       Heap memory       |" << std::endl;
	std::cout << "|-------------------------|" << std::endl;
	Zombie *wild;

	wild = newZombie("Heaper Jibber");
	wild->announce();
	std::cout << RED << "Deleting zombie..." << RESET << std::endl;
	delete wild;

	std::cout << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	std::cout << "|       Stack memory       |" << std::endl;
	std::cout << "|--------------------------|" << std::endl;
	randomChump("Stacky Maloney");
	std::cout << RED << "Deleting zombie..." << RESET << std::endl;
}
