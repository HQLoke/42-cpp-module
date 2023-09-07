#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange&	operator=(const BitcoinExchange &other);
		
		void	LoadData(const char *filename);
		float	GetPrice(const std::string date);

	private:
		std::map<std::string, float>	_priceData;
};

#endif 
