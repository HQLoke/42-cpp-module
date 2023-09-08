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
		
		float	GetPrice(const std::string &date);
		void	LoadData(const char *filename);
		bool	ParseDate(const std::string &date);
		bool	ParseValue(const std::string &value);

	private:
		std::map<std::string, float>	_priceData;
};

#endif 
