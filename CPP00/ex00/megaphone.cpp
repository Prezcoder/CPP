
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main (int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
		for (int j = 0; argv[i][j]; j++)
				cout << (char) toupper(argv[i][j]);
	cout << endl;
	return 0;
}
