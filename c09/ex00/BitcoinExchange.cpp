#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	read_file;
	std::string		line;
	std::string		date_data, price_data;

	read_file.open("data.csv");
	if (!read_file)
	{
		std::cout << "Please put the provided data.csv file in the same directory." << std::endl;
		exit(1);
	}
	
	do
	{
		std::getline(read_file, line);
		date_data = line.substr(0, line.find(','));
		price_data = line.substr(line.find(',') + 1, line.length());
		_priceData.insert(std::pair<std::string, float>(date_data, std::atof(price_data.c_str())));
	}
	while (line.length() > 0);
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

float	BitcoinExchange::GetPrice(const std::string date)
{
	std::map<std::string, float>::iterator	begin;

	begin = _priceData.begin();
	for (; begin != _priceData.end(); begin++)
	{
		if (begin->first == date)
			return (begin->second);
	}
	return (-1);
}
