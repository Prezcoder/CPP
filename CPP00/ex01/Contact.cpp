#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Constructor contact" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Destructor contact" << std::endl;
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
	_firstName = firstName;
}

void Contact::set_LastName(std::string lastName)
{
	_lastName = lastName;
}

void Contact::set_Nickname(std::string nickname)
{
	_nickname = nickname;
}

void Contact::set_PhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::set_DarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void Contact::printContact() const
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}