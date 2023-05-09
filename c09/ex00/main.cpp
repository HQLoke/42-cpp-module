#include "BitcoinExchange.hpp"

bool	parseDate(std::string date)
{
	int	temp[3];

	if (date.length() != 10)
		return (false);
	
	temp[0] = std::atoi(date.substr(0, 4).c_str());
	temp[1] = std::atoi(date.substr(5, 6).c_str());
	temp[2] = std::atoi(date.substr(8, 9).c_str());

	if ((temp[0] >= 2009 && temp[0] <= 2023)
		&& (temp[1] >= 1 && temp[1] <= 12)
		&& (temp[2] >= 1 && temp[2] <= 31))
		return (true);
	return (false);
}

bool	parseValue(std::string value)
{
	float	temp;

	temp = std::atof(value.c_str());
	if (value == "")
	{
		std::cout << "Error: no value is given on this date." << std::endl;
		return (false);
	}
	else if (temp < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (temp > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "This program only takes a single argument." << std::endl;
		return (1);
	}

	/* ---------------------------------------------------------------- */
	
	std::ifstream	input_txt;
	input_txt.open(argv[1]);
	if (!input_txt)
	{
		std::cout << "File is not found/file cannot be opened." << std::endl;
		exit(1);
	}

	/* ---------------------------------------------------------------- */

	BitcoinExchange	my_ex;
	std::string	line;
	std::getline(input_txt, line);
	while (std::getline(input_txt, line))
	{
		std::istringstream	iss(line);
		std::string			a, b, c;
		
		iss >> a >> b >> c;
		if (parseDate(a) == false)
			std::cout << "Error: bad input => " << a << std::endl;
		else if (parseDate(a) == true && parseValue(c) == true)
		{
			float	get = my_ex.GetPrice(a);
			if (get == -1)
				std::cout << "The date is out of range. No data is available." << std::endl;
			else
				std::cout << a << " => " << c << " = " << get * std::atof(c.c_str()) << std::endl;
		}
	}

	/* ---------------------------------------------------------------- */

	return (0);
}
