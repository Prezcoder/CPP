#include <iostream>
#include <string>
#include <stdexcept>
#include "Converter.hpp"

enum ConversionType { INVALID = -1, CHAR = 0, INT = 1, DOUBLE = 2, FLOAT = 3, SPECIAL = 4 };

bool isSingleCharacter(const std::string& arg) {
	return arg.length() == 1 && !std::isdigit(arg[0]);
}

bool isValidInteger(const string& arg) {
	try {
		size_t pos;
		std::stoi(arg, &pos);
		return (pos == arg.length());
	} catch (const std::exception&) {
		return false;
	}
}

bool isValidDouble(const std::string& arg) {
	try {
		std::stod(arg);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

bool isValidFloat(const std::string& arg) {
	try {
		std::stof(arg);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

int getType(const string& arg) {
	if (arg == "nan" || arg == "nanf" || arg == "-inf" || arg == "-inff" || arg == "+inf" || arg == "+inff") {
		return SPECIAL;
	}
	if (isSingleCharacter(arg)) {
		return CHAR;
	}
	if (isValidInteger(arg)) {
		return INT;
	}
	if (isValidDouble(arg)) {
		return DOUBLE;
	}
	if (isValidFloat(arg)) {
		return FLOAT;
	}
	return INVALID;
}

bool checkString(const string& arg) {
	if (arg == "nan" || arg == "nanf" || arg == "-inf" || arg == "-inff" || arg == "+inf" || arg == "+inff")
		return true;
	size_t fIndex = arg.find('f');

	if (fIndex != string::npos) {
		if (fIndex != arg.length() - 1) {
			cerr << "Problem: takes only one 'f' and it should be at the end of the string" << endl;
			return false;
		}
	}
	size_t dotIndex = arg.find('.');
	if (dotIndex != string::npos) {
		size_t nextDotIndex = arg.find('.', dotIndex + 1);
		if (nextDotIndex != string::npos) {
			cerr << "Problem: More than one '.' in the string" << endl;
			return false;
		}
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
