#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
using std::string;
using std::cout;
using std::endl;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &copy);

private:

};

#endif