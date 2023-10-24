
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	this->_indexContact = 0;
	std::cout << "Constructor phonebook called" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor phonebook called" << std::endl;
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
		std::cout << input;
		std::getline(std::cin, str);
 		if (std::cin.fail())
				std::exit(-1);
	} while (str.empty());
	return str;
}

void Phonebook::addContact(Contact &contact)
{
	contact.set_FirstName(Phonebook::setContact("Firstname :"));
	contact.set_LastName(Phonebook::setContact("Lastname :"));
	contact.set_Nickname(Phonebook::setContact("Nickname :"));
	contact.set_PhoneNumber(Phonebook::setContact("Phone number :"));
	contact.set_DarkestSecret(Phonebook::setContact("Darkest secret :"));
	this->_index++;
}

int Phonebook::searchContact(void) const
{
	std::cout << "Search contact" << std::endl;
	int	index;

	if(this->_index == 0)
		{
			std::cout << "Phonebook is empty" << std::endl;
			return 1;
		}
	else
	{
		if (this->_index > this->_indexContact)
			index = this->_index;
		else
			index = this->_indexContact;
		std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
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
	   		std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << firstName << "|";
            std::cout << std::setw(10) << lastName << "|";
            std::cout << std::setw(10) << nickname << std::endl;
		}
		return 0;
	}
	return 0;
}

void Phonebook::exit(void) const
{
	std::cout << "Exit" << std::endl;
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