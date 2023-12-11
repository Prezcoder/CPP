
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error: could not open file." << endl;
		exit (1);
	}
	BitcoinExchange bitcoin;
	bitcoin.bitcoinExchanger(argv[1]);
	return (0);
}