
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	this->_indexContact = 0;
	cout << "Constructor phonebook called" << endl;
	cout << endl;
	cout << endl;
}

void Phonebook::welcome(void) const
{
	cout << "Welcome to the Phonebook" << endl;
	cout << "Commands: ADD, SEARCH, EXIT" << endl;
	cout << "Please enter a command:" << endl;
	cout << "> ";
}

Phonebook::~Phonebook(void)
{
	cout << "Destructor phonebook called" << endl;
}

Contact& Phonebook::getContact(int index)
{
	return this->_contact[index];
}

std::string Phonebook::setContact(std::string input)
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

void Phonebook::addContact(Contact &contact)
{
	contact.set_FirstName(Phonebook::setContact("Firstname     : "));
	contact.set_LastName(Phonebook::setContact("Lastname      : "));
	contact.set_Nickname(Phonebook::setContact("Nickname      : "));
	contact.set_PhoneNumber(Phonebook::setContact("Phone number  : "));
	contact.set_DarkestSecret(Phonebook::setContact("Darkest secret: "));
	cout << "Contact added" << endl;
	cout << endl;
	this->_index++;
}

void Phonebook::doAdd(Phonebook &phonebook) const
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


int Phonebook::getIndex(void) const
{
	return this->_index;
}

int	Phonebook::setIndex(int index)
{
	this->_index = index;
	return this->_index;
}

int Phonebook::getIndexContact(void) const
{
	return this->_indexContact;
}

int	Phonebook::setIndexContact(int index)
{
	this->_indexContact = index;
	return this->_indexContact;
}

int Phonebook::searchContact(void) const
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
		cout << "     Index|First name| Last name|  Nickname" << endl;
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

void	Phonebook::doSearch(Phonebook &phonebook) const
{
	int index(0);
	std::string input;

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
				if (index >= 0 && index < phonebook.getIndex()) {
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

void Phonebook::exit(void) const
{
	cout << endl;
	cout << "Exiting...and don't worry...we'll forget your Phonebook!" << endl;
	cout << endl;
}
