
#include "Phonebook.hpp"

#include <iostream>
#include <string>

#include <iostream>
#include <string>

int main() 
{
	Phonebook phonebook;
	std::string input;
	std::string command;
	int index;

	std::cout << "Welcome to the Phonebook" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "Please enter a command:" << std::endl;
	std::cout << "> ";

	while (std::getline(std::cin, input) && input != "EXIT")
	{
		if (input == "ADD")
		{
			if (phonebook.getIndex() < 8)
				phonebook.addContact(phonebook.getContact(phonebook.getIndex()));
			else
			{
				std::cout << "ATTENTION : the Phonebook is full" << std::endl;
				std::cout << "If you want to overwrite the first contact" << std::endl;
				std::cout << "Please enter ADD:" << std::endl;
				std::cout << "> ";
				phonebook.setIndex(0);
				phonebook.setIndexContact(8);
			}
			std::cout << "Please enter a command:" << std::endl;
			std::cout << "> ";
		}
		else if (input == "SEARCH")
		{
			if (phonebook.searchContact() != 1)
			{
				bool validIndex = false;
				while (!validIndex)
				{
					std::cout << "Index: ";
					if (std::cin >> index)
					{
						if (index >= 0 && index < phonebook.getIndex())
						{
							phonebook.getContact(index).printContact();
							validIndex = true;
						}
						else
							std::cout << "Invalid index" << std::endl;
					}
				}
			} 
		}
		else if (input != "SEARCH" || input != "ADD" || input != "EXIT")
			std::cout << "> ";
	}
	phonebook.exit();
	return 0;
}

