
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cerr;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void	readInput(char *argv);
		void	readCSV();
		double	findRate(string date, std::map<std::string, double> data);
		string 	moveDateBack(const string& date);

		// a fonction to check if the date is valid
		bool	isDateValid(const string& date);
		// a fonction to check if the price is valid and between 0 and 100000
		bool	isPriceValid(const string& value);


	private:
		std::map<std::string, double> _dataFromTheCSVFile;
		std::map<std::string, double> _dataFromTheInputFile;
		std::ifstream _fileFromInput;

};

#endif