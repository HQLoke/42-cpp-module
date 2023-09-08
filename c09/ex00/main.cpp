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
	std::string 		line;

	if (!in_file)
	{
		std::cout << "Input file cannot be opened." << std::endl;
		return (1);
	}

	try
	{
		btc.LoadData("./data/data.csv");
	}
	catch (const char *err)
	{
		std::cout << err << std::endl;
		return (1);
	}

	std::getline(in_file, line);
	while (std::getline(in_file, line))
	{
		try
		{
			std::istringstream	iss(line);
			std::string			date, separator, amount;
			float				price;

			iss >> date >> separator >> amount;
			if (btc.ParseDate(date) == true)
				price = btc.GetPrice(date);
			btc.ParseValue(amount);
			std::cout << date << " => " << amount << " = " << price * atof(amount.c_str()) << std::endl; 
		}
		catch (const char *err)
		{
			std::cout << err << std::endl;
		}
	}
	return (0);
}
