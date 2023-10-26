#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Zombie
{
public:
	Zombie(string name);
	~Zombie();
	void announce( void );

private:
	string _name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif