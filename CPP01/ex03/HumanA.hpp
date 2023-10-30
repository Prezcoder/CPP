#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(string name, Weapon &weapon);
	~HumanA(void);
	void attack(void);
	void setWeapon(Weapon weapon);
	void setName(string name);

private:
	string _name;
	Weapon &_weapon;

};

#endif