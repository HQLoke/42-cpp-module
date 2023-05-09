#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include "stdlib.h"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		
		float	GetPrice(const std::string date);

	private:
		std::map<std::string, float>	_priceData;
};

#endif 
