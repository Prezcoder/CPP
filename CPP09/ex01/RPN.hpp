
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class RPN
{
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		RPN &operator=(const RPN &copy);

		void	convertToRPN(const string& expression);
		void	handleDigit(char digit);
		void	handleOperator(char op);
		void	handleInvalidChar();
		void	printResult();

	private:
		std::stack<int>	_numbers;
};

#endif