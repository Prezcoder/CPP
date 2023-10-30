
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	setName(string name);
		void 	announce( void );

	private:
		string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif