
#include "Zombie.hpp"

Zombie::Zombie(string name) : _name(name) {
	cout << "Zombie " << this->_name << " rises" << endl;
}

Zombie::~Zombie() {
	cout << "Zombie " << this->_name << " exploded" << endl;
}

void	Zombie::announce() {
	cout <<	this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}