#include "Converter.hpp"

// void	testScalarTypeFinder()
// {
// 	const char	*charTest[] = {"\n", "*", "-"};
// 	const char	*intTest[] = {"-2147483648", "0", "2147483647"};
// 	const char	*floatTest[] = {"-2147.483648f", "0.0f", "2147.483647f"};
// 	const char	*doubleTest[] = {"-2147.483648", "0.0", "2147.483647"};
// 	const char  *invalidTest[] = {"1.", ".1", "1..1", "-.", "-1.", "-.1"};
// 	Converter	example("");

// 	for (int i = 0; i < 3; i += 1)
// 	{
// 		std::string str(charTest[i]);
// 		if (example.scalarTypeFinder(str) != CHAR_TYPE)
// 			std::cerr << "Char: Error" << std::endl;

// 		std::string str2(intTest[i]);
// 		if (example.scalarTypeFinder(str2) != INT_TYPE)
// 			std::cerr << "Int: Error" << std::endl;
	
// 		std::string str3(floatTest[i]);
// 		if (example.scalarTypeFinder(str3) != FLOAT_TYPE)
// 			std::cerr << "Float: Error" << std::endl;

// 		std::string str4(doubleTest[i]);
// 		if (example.scalarTypeFinder(str4) != DOUBLE_TYPE)
// 			std::cerr << "Double: Error" << std::endl;
// 	}
// 	for (int i = 0; i < 7; i += 1)
// 	{
// 		std::string str(invalidTest[i]);
// 		if (example.scalarTypeFinder(str) != INVALID)
// 			std::cerr << "Invalid: Error" << std::endl;
// 	}
// }

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert [string_literal]" << std::endl;
		return (1);
	}
	// testScalarTypeFinder();
	Converter what(av[1]);
	what.storeValue();
	what.printResults();
}
