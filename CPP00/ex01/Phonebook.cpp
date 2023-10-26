
#include "Phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _indexContact(0)
{
	cout << "Constructor phonebook called" << endl;
	cout << endl;
	cout << endl;
}

void PhoneBook::welcome() const
{
	cout << "Welcome to the Phonebook" << endl;
	cout << "Commands: ADD, SEARCH, EXIT" << endl;
	cout << "Please enter a command:" << endl;
	cout << "> ";
}

PhoneBook::~PhoneBook()
{
	cout << "Destructor phonebook called" << endl;
}

Contact& PhoneBook::getContact(int index)
{
	return this->_contact[index];
}

std::string PhoneBook::setContact(std::string input)
{
	std::string str = "";

	do
	{
		cout << input;
		std::getline(std::cin, str);
 		if (cin.fail())
			std::exit(-1);
		for (int i(0); i < (int)str.length(); i++) {
			if (!isprint(str[i])) {
				cout << "Invalid entry" << endl;
				str.clear();
			}
		}
	} while (str.empty());
	return str;
}

void PhoneBook::addContact(Contact &contact)
{
	contact.set_FirstName(PhoneBook::setContact("Firstname     : "));
	contact.set_LastName(PhoneBook::setContact("Lastname      : "));
	contact.set_Nickname(PhoneBook::setContact("Nickname      : "));
	contact.set_PhoneNumber(PhoneBook::setContact("Phone number  : "));
	contact.set_DarkestSecret(PhoneBook::setContact("Darkest secret: "));
	cout << "Contact added" << endl;
	cout << endl;
	this->_index++;
}

void PhoneBook::doAdd(PhoneBook &phonebook) const
{
	if (phonebook.getIndex() < 8)
		phonebook.addContact(phonebook.getContact(phonebook.getIndex()));
	else
	{
		cout << "ATTENTION : the Phonebook is full" << endl;
		cout << "If you want to overwrite the first contact" << endl;
		cout << "Please enter ADD:" << endl;
		cout << "> ";
		phonebook.setIndex(0);
		phonebook.setIndexContact(8);
	}
	cout << "Please enter a command:" << endl;
	cout << "> ";
}


int PhoneBook::getIndex() const
{
	return this->_index;
}

int	PhoneBook::setIndex(int index)
{
	this->_index = index;
	return this->_index;
}

int PhoneBook::getIndexContact() const
{
	return this->_indexContact;
}

int	PhoneBook::setIndexContact(int index)
{
	this->_indexContact = index;
	return this->_indexContact;
}

int PhoneBook::searchContact() const
{
	cout << "Search contact" << endl;
	int	index;

	if(this->_index == 0)
		{
			cout << "Phonebook is empty" << endl;
			cout << "> ";
			return 1;
		}
	else
	{
		if (this->_index > this->_indexContact)
			index = this->_index;
		else
			index = this->_indexContact;
		cout << "   Index #|First name| Last name|  Nickname" << endl;
		for (int i = 0; i < index; i++)
		{
			std::string firstName = this->_contact[i].get_FirstName();
			std::string lastName = this->_contact[i].get_LastName();
			std::string nickname = this->_contact[i].get_Nickname();
			if (firstName.length() > 10)
				firstName = firstName.substr(0, 9) + ".";
			if (lastName.length() > 10)
				lastName = lastName.substr(0, 9) + ".";
			if (nickname.length() > 10)
				nickname = nickname.substr(0, 9) + ".";
	   		cout << std::setw(10) << i << "|";
            cout << std::setw(10) << firstName << "|";
            cout << std::setw(10) << lastName << "|";
            cout << std::setw(10) << nickname << endl;
		}
		return 0;
	}
	return 0;
}

void	PhoneBook::doSearch(PhoneBook &phonebook) const
{
	int index(0);
	std::string input;
	int	maxIndex;

	if (phonebook.searchContact() != 1) {
		bool validIndex = false;
		while (!validIndex) {
			cout << "Please enter a numerical index or EXIT to leave search mode" << endl; 
			cout << "Index: ";
			if (getline(cin, input) && input != "EXIT") {
				try {
					index = stoi(input);
				}
				catch(...) {
					cout << "Invalid entry" << endl;
					cout << endl;
					continue;
				}
				if (this->_index > this->_indexContact)
					maxIndex = this->_index;
				else
					maxIndex = this->_indexContact;
				if (index >= 0 && index < maxIndex) {
					cout << endl;
					cout << "Here's the contact " << index << ":" << endl;
					cout << endl;
					phonebook.getContact(index).printContact();
					validIndex = true;
				}
				else {
					cout << "Invalid index" << endl;
					cout << endl;
					}
				}
				if (input == "EXIT") {
				validIndex = true;
				cout << "Exiting search mode" << endl;
				cout << "Back to main menu" << endl;
				cout << "Please enter a command:" << endl;
				cout << "> ";
			}
			else if (cin.fail())
				std::exit(-1);
		}
	}
}

void PhoneBook::exit(void) const
{
	cout << endl;
	cout << "Exiting...and don't worry...we'll forget your Phonebook!" << endl;
	cout << endl;
}
