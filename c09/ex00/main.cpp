#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "This program only takes a single argument." << std::endl;
		return (1);
	}

	BitcoinExchange		btc;
	std::ifstream		in_file(argv[1]);
	std::string 		line, date, separator, amount;

	if (!in_file)
	{
		std::cout << "Input file cannot be opened." << std::endl;
		return (1);
	}

	try
	{
		btc.LoadData("./data/data.csv");

		std::getline(in_file, line);
		while (std::getline(in_file, line))
		{
			std::istringstream	iss(line);
			iss >> date >> separator >> amount;

			std::cout << date + "  ,  " + separator + "  ,  " + amount << std::endl; 
		}
	}
	catch (const char *err)
	{
		std::cout << err << std::endl;
	}
	return (0);
}
