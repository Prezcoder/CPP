#include "Bureaucrate.hpp"

Bureaucrate::Bureaucrate()
{
	cout << "Bureaucrate default constructor called" << endl;
}

Bureaucrate::Bureaucrate(const Bureaucrate &copy)
{
	cout << "Bureaucrate copy constructor called" << endl;
// PLACE PRIVATES //
	*this = copy;
}

Bureaucrate &Bureaucrate::operator=(const Bureaucrate &copy)
{
	cout << "Bureaucrate assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Bureaucrate::~Bureaucrate()
{
	cout << "Bureaucrate destructor called" << endl;
}