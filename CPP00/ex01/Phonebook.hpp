
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
	public:

		Phonebook(void);
		~Phonebook(void);
		Contact& getContact(int index);
		void		addContact(Contact &contact);
		int			searchContact(void) const;
		void		exit(void) const;
		int			getIndex(void) const;
		int			setIndex(int index);
		int			getIndexContact(void) const;
		int			setIndexContact(int index);
		void		printContact(void) const;
		std::string setContact(std::string input);
		// void 		printContact(Contact &contact) const;

	private:

		Contact _contact[8];
		int		_index;
		int		_indexContact;

};
# endif