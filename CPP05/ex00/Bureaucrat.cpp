#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    cout << "Bureaucrat copy constructor called" << endl;
   // PLACE PRIVATES //
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    cout << "Bureaucrat assignation operator called" << endl;
    if (this != &copy)
        _type = copy._type;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    cout << "Bureaucrat destructor called" << endl;
}