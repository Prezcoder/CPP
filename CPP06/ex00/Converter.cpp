
#include"Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(string str) : _str(str)
{
}

Converter::Converter(const Converter &copy)
{
	*this = copy;
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &copy)
{
	if (this == &copy)
		return (*this);
	_str = copy._str;
	return (*this);
}

void Converter::toChar()
{
	char c = _str[0];

	if (c <= 31)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << c << "'" << endl;
	
	cout << "int: " << fixed << static_cast<int>(c) << endl;
	cout << "float: " << fixed << setprecision(1) << static_cast<float>(c) << "f" << endl;
	cout << "double: " << fixed << setprecision(1) << static_cast<double>(c) << endl;
}

void Converter::toInt()
{
	int i = std::stoi(_str);

	if (i <= 127 && i >= 0)
	{
		if (i <= 31)
			cout << "char: Non displayable" << endl;
		else
			cout << "char: '" << static_cast<char>(i) << "'" << endl;
	}
	else
	{
		cout << "char: impossible" << endl;
	}

	cout << "int: " << i << endl;
	cout << "float: " << fixed << setprecision(1) << static_cast<float>(i) << "f" << endl;
	cout << "double: " << fixed << setprecision(1) << static_cast<double>(i) << endl;
}

void Converter::toFloat()
{
	float f = std::stof(_str);

	if (f <= 127 && f >= 0)
	{
		if (f <= 31)
			cout << "char: Non displayable" << endl;
		else
			cout << "char: '" << static_cast<char>(f) << "'" << endl;
	}
	else
	{
		cout << "char: impossible" << endl;
	}

	if (f > INT_MAX || f < INT_MIN)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << fixed << static_cast<int>(f) << endl;

	cout << "float: " << fixed << setprecision(1) << f << "f" << endl;
	cout << "double: " << fixed << setprecision(1) << static_cast<double>(f) << endl;
}

void Converter::toDouble()
{
	double d = std::stod(_str);

	if (d <= 127 && d >= 0)
	{
		if (d <= 31)
			cout << "char: Non displayable" << endl;
		else
			cout << "char: '" << static_cast<char>(d) << "'" << endl;
	}
	else
	{
		cout << "char: impossible" << endl;
	}
	if (d > INT_MAX || d < INT_MIN)
		cout << "int: impossible" << endl;
	else
		cout << "int: " << fixed << static_cast<int>(d) << endl;
	cout << "float: " << fixed << setprecision(1) << static_cast<float>(d) << "f" << endl;
	cout << "double: " << fixed << setprecision(1) << d << endl;

}

void Converter::toSpecial()
{
	string str = _str;
	cout << "char : impossible" << endl;
	cout << "int : impossible" << endl;
	if (str == "nan" || str == "nanf")
	{
		cout << "float: nanf" << endl;
		cout << "double: nan" << endl;
	}
	else if (str == "+inf" || str == "-inf")
	{
		cout << "float: " << str + "f" << endl;
		cout << "double: " << str << endl;
	}
	else if (str == "+inff" || str == "-inff")
	{
		cout << "float: " << str << endl;
		cout << "double: " << str.substr(0, str.length() -1) << endl;
	}
}

void Converter::printError()
{
	cout << "char : impossible" << endl;
	cout << "int : impossible" << endl;
	cout << "float: impossible" << endl;
	cout << "double: impossible" << endl;
}