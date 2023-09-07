#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include "stdlib.h"
#include "string.h"

bool	is_leap_year(int year);
bool	is_valid_date(const std::string &date);
bool	is_valid_value(const std::string value);

/*
**	Constructor, destructor, copy constructor, copy assignment operator
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_priceData = other._priceData;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->_priceData = other._priceData;
	return (*this);
}

/*
**	Methods
*/

void	BitcoinExchange::LoadData(const char *filename)
{
	std::ifstream		input(filename);
	std::string			line, date, value;

	if (!input)
		throw ("File is not found/file cannot be opened.");
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		std::istringstream	line_stream(line);

		std::getline(line_stream, date, ',');
		std::getline(line_stream, value);

		if (is_valid_date(date) == true)
			_priceData.insert(std::pair<std::string, float>(date, atof(value.c_str())));
	}

	input.close();
}

float	BitcoinExchange::GetPrice(const std::string date)
{
	is_valid_date(date);
	return (-1);
}

/*
**	Functions
*/

bool	is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return (true);
	else if (year % 400 == 0)
		return (true);
	return (false);
}

bool	is_valid_date(const std::string &date)
{
	std::istringstream	iss(date);
	int		year, month, day;
	char	dash1, dash2;

	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
		throw ("Invalid date format");
	
	if (month < 1 || month > 12)
		throw ("Invalid month.");

	if (day < 1 || day > 31)
		throw ("Invalid day.");

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw ("April, June, September & November have 30 days only.");

	if (month == 2)
	{
		if (is_leap_year(year) && day > 29)
			throw ("February has 29 days in a leap year.");
		else if (!is_leap_year(year) && day > 28)
			throw ("February has 28 days in a leap year.");
	}

	return (true);
}

bool	is_valid_value(const std::string value)
{
	float	temp;

	temp = atof(value.c_str());
	if (value == "")
		throw ("Error: no value is given on this date.");
	
	if (temp < 0)
		throw ("Error: not a positive number.");
	
	if (temp > 1000)
		throw ("Error: too large a number.");

	return (true);
}
