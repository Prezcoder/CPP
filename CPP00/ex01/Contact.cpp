
#include "Contact.hpp"

Contact::Contact()
{
	cout << "Constructor contact" << endl;
}

Contact::~Contact()
{
	cout << "Destructor contact" << endl;
}

std::string Contact::get_FirstName() const
{
	return this->_firstName;
}

std::string Contact::get_LastName() const
{
	return this->_lastName;
}

std::string Contact::get_Nickname() const
{
	return this->_nickname;
}

std::string Contact::get_PhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::get_DarkestSecret() const
{
	return this->_darkestSecret;
}

void Contact::set_FirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::set_LastName(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::set_Nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::set_PhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::set_DarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::printContact() const
{
	cout << "First name    : " << this->_firstName << endl;
	cout << "Last name     : " << this->_lastName << endl;
	cout << "Nickname      : " << this->_nickname << endl;
	cout << "Phone number  : " << this->_phoneNumber << endl;
	cout << "Darkest secret: " << this->_darkestSecret << endl;
	cout << endl;
	cout << "Back to main menu" << endl;
	cout << "Please enter a command:" << endl;
	cout << "> ";
}