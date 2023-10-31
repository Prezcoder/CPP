
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Weapon
{
	public:
		Weapon(string type);
		~Weapon(void);
		void setType(string type);
		string const &getType(void);

	private:
		string _type;

};

#endif