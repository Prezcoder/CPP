
#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>

using std::cout;
using std::endl;
using std::cin;

class Contact
{
public:

	Contact(void);
	~Contact(void);
	std::string get_FirstName(void) const;
	std::string get_LastName(void) const;
	std::string get_Nickname(void) const;
	std::string get_PhoneNumber(void) const;
	std::string get_DarkestSecret(void) const;
	void 		set_FirstName(std::string firstName);
	void 		set_LastName(std::string lastName);
	void 		set_Nickname(std::string nickname);
	void 		set_PhoneNumber(std::string phoneNumber);
	void 		set_DarkestSecret(std::string darkestSecret);
	void 		printContact(void) const;

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif