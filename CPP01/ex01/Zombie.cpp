
#include "Zombie.hpp"

Zombie::Zombie() {
	cout << "Zombie" << this->_name << " rises" << endl;
}

Zombie::~Zombie() {
	cout << "Zombie " << this->_name << " exploded" << endl;
}

void	Zombie::announce() {
	cout <<	this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::setName(string name) {
	this->_name = name;
}