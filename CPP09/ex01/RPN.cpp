
#include "RPN.hpp"

RPN::RPN() :  _numbers() {}

RPN::RPN(const RPN &copy) : _numbers(copy._numbers) {
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy) {
	if (this != &copy)
		_numbers = copy._numbers;
	return (*this);
}

void RPN::handleDigit(char digit) {
	_numbers.push(digit - '0');
}

void RPN::handleOperator(char operatorChar) {
	if (_numbers.size() < 2) {
		cerr << "Error: Insufficient operands for operator " << operatorChar << endl;
		exit(1);
	}
	int a = _numbers.top();
	_numbers.pop();
	int b = _numbers.top();
	_numbers.pop();

	switch (operatorChar) {
		case '+': _numbers.push(a + b); break;
		case '-': _numbers.push(b - a); break;
		case '*': _numbers.push(a * b); break;
		case '/':
			if (a != 0)
				_numbers.push(b / a);
			else
				cerr << "Error: Division by zero" << endl;
			break;
		default:
			cerr << "Error: Invalid operator" << endl;
			break;
	}
}

void RPN::handleInvalidChar() {
	cerr << "Error: Invalid expression" << endl;
	exit(1);
}

void RPN::convertToRPN(const string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		char currentChar = input[i];

		if (isdigit(currentChar))
			handleDigit(currentChar);
		else if (currentChar == '+' || currentChar == '-' || currentChar == '*'
				|| currentChar == '/' || currentChar == '%')
			handleOperator(currentChar);
		else if (currentChar == ' ')
			continue;
		else
			handleInvalidChar();
	}
}

void	RPN::printResult() {
	if (_numbers.size() == 1)
		cout << _numbers.top() << endl;
}
