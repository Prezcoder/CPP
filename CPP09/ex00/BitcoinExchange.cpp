
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	cout << "BitcoinExchange default constructor called" << endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	cout << "BitcoinExchange copy constructor called" << endl;
// PLACE PRIVATES //
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	cout << "BitcoinExchange assignation operator called" << endl;
	if (this != &copy)
		// _type = copy._type;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	cout << "BitcoinExchange destructor called" << endl;
}