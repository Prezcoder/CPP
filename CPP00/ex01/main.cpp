
#include "Phonebook.hpp"

int main() 
{
	Phonebook phonebook;
	std::string input;

	phonebook.welcome();
	while (std::getline(std::cin, input) && input != "EXIT")
	{
		if (input == "ADD")
			phonebook.doAdd(phonebook);
		else if (input == "SEARCH")
			phonebook.doSearch(phonebook); 
		else if (cin.fail())
			exit(-1);
		else {
			std::cout << "Invalid command" << std::endl;
			cout << "> ";
		}
	}
	phonebook.exit();
	return 0;
}

