# include "Zombie.hpp"

/*
 * Object of class Zombie is created in the stack memory.
 * All memory allocated is destroyed after return.
 * Destructor will be called when exiting the function scope.
 */
void	randomChump(std::string name)
{
	Zombie biter(name);
	biter.announce();
}
