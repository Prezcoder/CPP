#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include<iostream>
using std::string;
using std::cout;
using std::endl;

class Bureaucrate
{
public:
	Bureaucrate();
	Bureaucrate(const Bureaucrate &copy);
	~Bureaucrate();

	Bureaucrate &operator=(const Bureaucrate &copy);

private:

};

#endif