
#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	cout << "HumanA created" << endl;
}

HumanA::~HumanA() {
	cout << "HumanA destroyed" << endl;
}

void HumanA::attack() {
	cout << this->_name << " attacks with their " << this->_weapon.getType() << endl;
}

void HumanA::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
}

void HumanA::setName(string name) {
	this->_name = name;
}
