#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(string name);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon &weapon);
    void setName(string name);


private:
    string _name;
    Weapon *_weapon;

};

#endif