
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// cout << "BitcoinExchange default constructor called" << endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	// cout << "BitcoinExchange copy constructor called" << endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	// cout << "BitcoinExchange assignation operator called" << endl;
	if (this != &copy)
	{
		_dataFromTheCSVFile = copy._dataFromTheCSVFile;
		_dataFromTheInputFile = copy._dataFromTheInputFile;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	// cout << "BitcoinExchange destructor called" << endl;
}

void	BitcoinExchange::readCSV()
{
	string line;
	string date;
	string rate;
	std::ifstream fileFromCSV("data.csv");
	getline(fileFromCSV, line);
	if (fileFromCSV.is_open())
	{
		while (getline(fileFromCSV, line))
		{
			std::stringstream ss(line);
			getline(ss, date, ',');
			getline(ss, rate, ',');
			_dataFromTheCSVFile[date] = std::stod(rate);
		}
	}
}

void	BitcoinExchange::readInput(char *argv)
{
	string line;
	string date;
	string value;
	std::ifstream fileFromInput(argv);
	if (!fileFromInput.is_open())
	{
		cerr << "Error: could not open file." << endl;
		exit (1);
	}
	getline(fileFromInput, line);
	while (getline(fileFromInput, line))
	{
		std::stringstream ss(line);
		char separator;
		if (!(ss >> date >> separator >> value) || separator != '|')
			cout << "Error: bad input => " << date << endl;
		else if (!isDateValid(date) || !isPriceValid(value))
			cout << "Error: bad input => " << date << endl;
		else if (stod(value) < 0)
			cout << "Error: not a positive number." << endl;
		else if (stod(value) > 1000)
			cout << "Error: too large a number." << endl;
		else if (stod(value) < 1000 || stod(value) > 0) {
			std::map<std::string, double>::iterator it = _dataFromTheCSVFile.find(date);
			it = _dataFromTheCSVFile.lower_bound(date);
			if ((it != _dataFromTheCSVFile.begin() && it == _dataFromTheCSVFile.end()) || it->first > date)
				it--;
			double rate = it->second;
			double multiplication = stod(value) * rate;
			cout << date << " => " << value << " = " << multiplication << endl;
		}
		else
			cout << "Error: bad input => " << date << endl;
	}
	fileFromInput.close();
}

bool	BitcoinExchange::isDateValid(const string& date)
{
	if (date.length() != 10)
		return (false);
	int year, month, day;
	char separator1, separator2;
	std::istringstream ss(date);
	ss >> year >> separator1 >> month >> separator2 >> day;
	if (ss.fail() || separator1 != '-' || separator2 != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if ((month == 2 && (leap_year ? day > 29 : day > 28)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
	{
		cout << "idil" << endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isPriceValid(const string& value)
{
	try{
		std::stod(value);
	}
	catch (const std::exception& e)
	{
		return (false);
	}
	return (true);
}
