
#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name), _weapon(NULL) {
	cout << "HumanB created" << endl;
}

HumanB::~HumanB() {
	cout << "HumanB destroyed" << endl;
}

void HumanB::attack() {
	if (this->_weapon == NULL)
		cout << this->_name << " has no weapon" << endl;
	else
		cout << this->_name << " attacks with their " << this->_weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::setName(string name) {
	this->_name = name;
}
