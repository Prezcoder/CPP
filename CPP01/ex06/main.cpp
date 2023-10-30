
#include "Harl.hpp"

int	translation(char *argv)
{
	string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			return (i);
	return (-1);
}

void	complain_switch(char *argv, Harl &harl)
{
	switch(translation(argv))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
}

int main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
		cout << "[ Probably complaining about insignificant problems ]" << endl;
	else
		complain_switch(argv[1], harl);
	return 0;
}