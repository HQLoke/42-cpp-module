#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [string_literal]" << std::endl;
		return (1);
	}
	Converter	var(av[1]);
	const char	*macro[] = {"", "Char", "Integer", "Float", "Double", "Invalid"};

	var.printResults();
	std::cout << "\nScalar type: " << macro[var.getScalarType()] << std::endl;

	return (0);
}
