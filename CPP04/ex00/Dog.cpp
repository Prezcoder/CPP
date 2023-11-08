
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	cout << this->_type << " constructor called" << endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	cout << "Dog copy constructor called" << endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
	cout << "Dog assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void Dog::makeSound() const {
	cout << "The " << this->_type << " barks!" << endl;
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
}