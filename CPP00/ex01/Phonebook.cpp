
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Constructor phonebook called" << std::endl;
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
	std::string str;

	do
	{
		std::cout << input;
		std::cin >> str;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (str.length() > 0 && str.length() < 20)
			break;
		std::cout << "Invalid length" << std::endl;
	} while (std::cin && str.length() > 0 && str.length() < 20);
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
	
	if(this->_index == 0)
		{
			std::cout << "Phonebook is empty" << std::endl;
			return 1;
		}
	else
	{
		std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
		for (int i = 0; i < this->_index; i++)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << this->_contact[i].get_FirstName() << "|";
			std::cout << std::setw(10) << this->_contact[i].get_LastName() << "|";
			std::cout << std::setw(10) << this->_contact[i].get_Nickname() << std::endl;
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