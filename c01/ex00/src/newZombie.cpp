# include "Zombie.hpp"

/*
 * Object of class Zombie is created in the heap memory.
 * All memory allocated is not destroyed after return.
 * Destructor will not be called when exiting the function scope.
 */
Zombie	*newZombie(std::string name)
{
	Zombie	*ret;

	ret = new Zombie(name);
	return (ret);
}
