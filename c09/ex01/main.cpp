#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdlib.h>

bool	is_operator(const char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

double	perform_operation(double first, double second, const char c)
{
	if (c == '+')
		return (first + second);
	else if (c == '-')
		return (first - second);
	else if (c == '/')
		return (first / second);
	else if (c == '*')
		return (first * second);
	return (-1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "This program only takes a single argument." << std::endl;
		return (1);
	}

	/* ---------------------------------------------------------------- */

	std::istringstream	iss(argv[1]);
	std::string			token;
	std::stack<double>	lifo;
	double				first, second;

	try
	{
		while (iss >> token)
		{
			if (isdigit(token[0]) == true)
			{
				if (token.length() != 1)
					throw ("Number is not less than 10, or is a decimal number.");
				lifo.push(atof(token.c_str()));
			}
			else if (is_operator(token[0]) == true)
			{
				if (lifo.size() <= 1)
					throw ("Insufficient numbers to perform operation on.");
				second = lifo.top();
				lifo.pop();
				first = lifo.top();
				lifo.pop();
				lifo.push(perform_operation(first, second, token[0]));
			}
			else
				throw ("Error: using forbidden character.");
		}
		if (lifo.size() > 1)
			throw ("Not enough operations to perform on all the numbers.");
	}
	catch (const char *err)
	{
		std::cout << err << std::endl;
		exit (1);
	}

	/* ---------------------------------------------------------------- */
	std::cout << lifo.top() << std::endl;

	return (0);
}
