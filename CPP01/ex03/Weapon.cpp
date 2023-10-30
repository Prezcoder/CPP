
#include "Weapon.hpp"

Weapon::Weapon(string type) : _type(type) {
	this->_type = type;
	cout << "Weapon created" << endl;
}

Weapon::~Weapon() {
	cout << "Weapon destroyed" << endl;
}

void Weapon::setType(string type) {
	this->_type = type;
}

string Weapon::getType() const {
	return this->_type;
}
