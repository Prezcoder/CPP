
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
public:

	Phonebook(void);
	~Phonebook(void);
	const Contact *getContact(int index) const;

private:

	Contact _contacts[8];
	int		_index;

};
# endif