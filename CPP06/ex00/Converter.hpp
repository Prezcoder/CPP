
#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>

using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::cerr;

class Converter
{
	private:
		string _str;
		Converter();
	public:
		Converter(string str);
		Converter(const Converter &copy);
		~Converter();
		Converter &operator=(const Converter &copy);

		void toChar();
		void toInt();
		void toFloat();
		void toDouble();
		void toSpecial();
		void printError();
};

#endif