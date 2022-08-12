#include "Zombie.hpp"

int main(void)
{
	Zombie	*wild;
	int		size;

	std::cout << "|----------------------------|" << std::endl;
	std::cout << "|       First stampede       |" << std::endl;
	std::cout << "|----------------------------|" << std::endl;
	size = 20;
	wild = zombieHorde(size, "First stampede");
	for (int i = 0; i < size; i += 1)
	{
		std::cout << "Zombie number " << i + 1 << ": ";
		wild[i].announce();
	}
	delete[] wild;

	std::cout << std::endl;
	std::cout << "|-----------------------------|" << std::endl;
	std::cout << "|       Second uprising       |" << std::endl;
	std::cout << "|-----------------------------|" << std::endl;
	size = 42;
	wild = zombieHorde(size, "Second uprising");
	for (int i = 0; i < size; i += 1)
	{
		std::cout << "Zombie number " << i + 1<< ": ";
		wild[i].announce();
	}
	delete[] wild;
	return (0);
}
