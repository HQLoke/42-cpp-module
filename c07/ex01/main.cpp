#include "iter.hpp"

int main(void)
{
	char	*str = strdup("Hello World");
	iter<char>(str, strlen(str), &print);
	
	std::cout << "\n" << std::endl;

	int		integer[5] = {1, 2, 3, 4, 5};
	iter<int>(integer, 5, &print);

	std::cout << "\n" << std::endl;

	long	longer[5] = {2147483666, 2147483667, 2147483668, 2147483669, 2147483670};
	iter<long>(longer, 5, &print);

	std::cout << "\n" << std::endl;

	double	floating[5] = {0.042, 0.42, 4.2, 42.0, 420.0};
	iter<double>(floating, 5, &print);

	std::cout << "\n" << std::endl;

	std::string	names[5] = {"Alice", "Bob", "Charles", "Dave", "Erik"};
	iter<std::string>(names, 5, &print);

	std::cout << "\n" << std::endl;
}
