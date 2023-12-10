
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::getline;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void	readInput(char *argv);
		void	readCSV();

		bool	isDateValid(const string& date);
		bool	isPriceValid(const string& value);

	private:
		std::map<string, double> _dataFromTheCSVFile;
		std::ifstream _fileFromInput;
};

#endif