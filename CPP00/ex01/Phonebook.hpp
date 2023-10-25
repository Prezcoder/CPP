
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);
		Contact& 	getContact(int index);
		std::string setContact(std::string input);
		void		addContact(Contact &contact);
		int			searchContact(void) const;
		void		welcome(void) const;
		void		exit(void) const;
		int			getIndex(void) const;
		int			setIndex(int index);
		int			getIndexContact(void) const;
		int			setIndexContact(int index);
		void		printContact(void) const;
		void		doSearch(PhoneBook &phonebook) const;
		void		doAdd(PhoneBook &phonebook) const;

	private:

		Contact _contact[8];
		int		_index;
		int		_indexContact;

};

# endif