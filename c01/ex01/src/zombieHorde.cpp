#include "Zombie.hpp"

/* 
 * Array new cannot have initialization arguments.
 * Use setter function instead.
 */
Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*zom;
	int		i;

	zom = new Zombie[N];
	i = -1;
	while (++i < N)
	{
		zom[i].setName(name);
	}
	return (zom);
}
