
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error: Wrong number of arguments" << endl;
		return (1);
	}
	RPN rpn;
	rpn.convertToRPN(argv[1]);
	rpn.printResult();
	return (0);
}