
#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;
	int index;

	while(std::cin >> command && command != "EXIT")
	{
		if (command == "ADD")
		{
			if (phonebook.getIndex() < 8)
				phonebook.addContact(phonebook.getContact(phonebook.getIndex()));
			else
				{
					std::cout << "Phonebook is full" << std::endl;
					std::cout << "We will overwrite the first contact" << std::endl;
					phonebook.setIndex(0);
				}
		}
		else if (command == "SEARCH")
		{
			if(phonebook.searchContact() != 1)
			{
				std::cout << "Index: ";
				std::cin >> index;
				if (index >= 0 && index < phonebook.getIndex())
					phonebook.getContact(index).printContact();
				else
					std::cout << "Invalid index" << std::endl;
			}
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	phonebook.exit();
	return 0;
}