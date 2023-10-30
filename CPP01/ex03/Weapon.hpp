
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
		string getType(void) const;

	private:
		string _type;

};

#endif