#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "This program only takes a single argument." << std::endl;
		return (1);
	}

	/* ---------------------------------------------------------------- */

	RPN	math1(argv[1]);
	math1.Calculate();

	/* ---------------------------------------------------------------- */

	return (0);
}
