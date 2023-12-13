
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()  : _fileFromInput(), _fileFromCSV() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _dataFromTheCSVFile(copy._dataFromTheCSVFile) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		_dataFromTheCSVFile = copy._dataFromTheCSVFile;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	if (_fileFromCSV.is_open())
		_fileFromCSV.close();
	if (_fileFromInput.is_open())
		_fileFromInput.close();
}

void BitcoinExchange::bitcoinExchanger(const string& filename) {
	readCSVFile();
	createMapWithCSV();
	readInputFile(filename);
	parseInputFile();
}

void	BitcoinExchange::readCSVFile() {
	try {
		_fileFromCSV.open("data.csv");
		if (!_fileFromCSV.is_open())
			throw std::invalid_argument("could not open file 'data.csv'.");
	}
	catch(std::exception &e) {
		cerr << "Error : " << e.what() << endl;
		exit(1);
	}
}

void	BitcoinExchange::createMapWithCSV() {
	string line, date, rate;
	const string CSV_HEADER = "date,exchange_rate";
	
	getline(_fileFromCSV, line);
	if (line.compare(CSV_HEADER))
		cerr << "Error: First line of file is not '" << CSV_HEADER << "'. Might not be a valid file. Please verify." << endl;
	while (getline(_fileFromCSV, line))
	{
		std::stringstream ss(line);
		getline(ss, date, ',');
		getline(ss, rate, ',');
		if (!findMoreThanOneDot(rate))
			cerr << "Error: More than one '.' in CSV => " << rate << endl;
		else if (!isDateValid(date) || !isPriceValid(rate))
			cerr << "Error: bad input in CSV => " << date << endl;
		else
			_dataFromTheCSVFile[date] = std::stod(rate);
	}
}

void BitcoinExchange::readInputFile(const string& filename) {
	try {
		_fileFromInput.open(filename);
		if (!_fileFromInput.is_open())
			throw std::invalid_argument("could not open input file.");
	}
	catch(std::exception &e) {
		cerr << "Error : " << e.what() << endl;
		exit(1);
	}
}

void	BitcoinExchange::printingResults(const string& date, const string& value) {
	std::map<string, double>::const_iterator it = _dataFromTheCSVFile.find(date);
	it = _dataFromTheCSVFile.lower_bound(date);
	if (it == _dataFromTheCSVFile.end() || it->first > date)
		it--;
	double rate = it->second;
	double multiplication = stod(value) * rate;
	cout << date << " => " << stod(value) << " = " << multiplication << endl;
}

bool	BitcoinExchange::findMoreThanOneDot(const string& value) {
	size_t dotIndex = value.find('.');
	if (dotIndex != string::npos) {
		size_t nextDotIndex = value.find('.', dotIndex + 1);
		if (nextDotIndex != string::npos)
			return false;
	}
	return true;
}

void	BitcoinExchange::parseInputFile() {
	string line, date, value;
	const string INPUT_HEADER = "date | value";

	getline(_fileFromInput, line);
	if (line.compare(INPUT_HEADER))
		cerr << "Error: First line of file is not '" << INPUT_HEADER << "'. Might not be a valid file. Please verify." << endl;
	while (getline(_fileFromInput, line))
	{
		std::stringstream ss(line);
		char separator;
		if (!(ss >> date >> separator >> value) || separator != '|')
			cerr << "Error: bad input => " << date << endl;
		else if (!findMoreThanOneDot(value))
			cerr << "Error: More than one '.' => " << value << endl;
		else if (!isDateValid(date) || !isPriceValid(value))
			cerr << "Error: bad input => " << date << endl;
		else if (stod(value) < 0)
			cerr << "Error: not a positive number." << endl;
		else if (stod(value) > 1000)
			cerr << "Error: too large a number." << endl;
		else if (stod(value) < 1000 || stod(value) > 0) 
			printingResults(date, value);
		else
			cerr << "Error: bad input => " << date << endl;
	}
}

bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool	BitcoinExchange::isDateValid(const string& date) {
	if (date.length() != 10)
		return (false);
	int year, month, day;
	char separator1, separator2;
	std::istringstream ss(date);
	ss >> year >> separator1 >> month >> separator2 >> day;
	if (ss.fail() || separator1 != '-' || separator2 != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	bool leap_year = isLeapYear(year);
	if ((month == 2 && (leap_year ? day > 29 : day > 28)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		return (false);
	return (true);
}

bool	BitcoinExchange::isPriceValid(const string& value) {
	try {
		stod(value);
	}
	catch (const std::exception& e) {
		return (false);
	}
	return (true);
}
