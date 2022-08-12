#include <iostream>

/*
 * https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/
 */
int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "|---------------------|" << std::endl;
	std::cout << "|       Address       |" << std::endl;
	std::cout << "|---------------------|" << std::endl;
	std::cout << "Address of str      : " << &str << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "|---------------------------|" << std::endl;
	std::cout << "|       Display value       |" << std::endl;
	std::cout << "|---------------------------|" << std::endl;
	std::cout << "Value of str      : " << str << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "|----------------------------|" << std::endl;
	std::cout << "|       Changing value       |" << std::endl;
	std::cout << "|----------------------------|" << std::endl;
	*stringPTR = "I'M USING POINTER TO CHANGE VALUE";
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	stringREF = "I'M USING REFERENCE TO CHANGE VALUE";
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	return (0);
}
