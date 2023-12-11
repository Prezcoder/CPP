
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
using std::stod;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void	bitcoinExchanger(char *argv);
		void	readCSVFile();
		void	createMapWithCSV();
		void	readInputFile(char *argv);
		void	parseInputFile();
		void	printingResults(const string &date, const string& value);
		bool	isDateValid(const string& date);
		bool	isPriceValid(const string& value);

	private:
		std::map<string, double> _dataFromTheCSVFile;
		std::ifstream _fileFromInput;
		std::ifstream _fileFromCSV;
};

#endif