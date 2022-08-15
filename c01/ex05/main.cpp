#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harl [DEBUG/ERROR/INFO/WARNING]\n";
		exit (EXIT_FAILURE);
	}
	Harl	idiot;
	idiot.complain(av[1]);
	return (0);
}
