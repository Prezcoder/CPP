#include <iostream>
#include <string>
#include <stdexcept>
#include "Converter.hpp"

enum ConversionType { INVALID = -1, CHAR = 0, INT = 1, DOUBLE = 2, FLOAT = 3, SPECIAL = 4 };

int getType(const string& arg) {
	if (arg == "nan" || arg == "nanf" || arg == "-inf" || arg == "-inff" || arg == "+inf" || arg == "+inff")
		return SPECIAL;
	try {
		if (arg.length() > 11 || arg.empty())
			throw std::invalid_argument("not a valid number");
	} catch (const std::invalid_argument&) {
		return INVALID;
	} 
	if (arg.length() == 1 && arg.find_first_of("0123456789") == string::npos)
		return CHAR;
	try {
		size_t pos;
		int value = std::stoi(arg, &pos);
		if (pos != arg.length()) {
			throw std::invalid_argument("not a valid integer");
		}
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
			throw std::out_of_range("integer out of range");
		}
		return INT;
	} catch (std::exception) {
		try {
			std::stod(arg);
			if (arg.find_first_not_of("0123456789.+-") != string::npos || arg.length() > 11)
				throw std::invalid_argument("not a valid double");
			return DOUBLE;
		} catch (const std::invalid_argument&) {
			try {
				std::stof(arg);
				if (arg.find_first_not_of("0123456789f.+-") != string::npos || arg.length() > 11)
					throw std::invalid_argument("not a valid float");
				return FLOAT;
			} catch (const std::invalid_argument&) {
				return INVALID;
			}
		}
	}
}

bool checkString(const string& arg) {
	if (arg == "nan" || arg == "nanf" || arg == "-inf" || arg == "-inff" || arg == "+inf" || arg == "+inff")
		return true;

	size_t firstIndex = arg.find('f');
	if (firstIndex != string::npos && firstIndex + 1 != string::npos) {
		cerr << "Problem: More than one 'f' in the string" << endl;
		return false;
	}
	firstIndex = arg.find('.');
	if (firstIndex != string::npos && firstIndex + 1 != string::npos) {
		cerr << "Problem: More than one '.' in the string" << endl;
		return false;
	}
	return true;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cerr << "Error: Wrong number of arguments" << endl;
		return 1;
	}

	string input = argv[1];

	if (!checkString(input))
		return 1;

	Converter argConverter(input);

	switch (getType(input)) {
		case CHAR:
			argConverter.toChar();
			break;
		case INT:
			argConverter.toInt();
			break;
		case DOUBLE:
			argConverter.toDouble();
			break;
		case FLOAT:
			argConverter.toFloat();
			break;
		case SPECIAL:
			argConverter.toSpecial();
			break;
		default:
			argConverter.printError();
	}

	return 0;
}
