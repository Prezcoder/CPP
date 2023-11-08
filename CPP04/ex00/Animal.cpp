
#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	cout << "Animal default constructor called" << endl;
}

Animal::Animal(string type) : _type(type) {
	cout << "Animal " << this->_type << " constructor called" << endl;
}

Animal::Animal(const Animal &copy) {
	cout << "Animal copy constructor called" << endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
	cout << "Animal assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void Animal::makeSound() const {
	cout << "Generic animal sound..." << endl;
}

string Animal::getType() const {
	return (this->_type);
}

Animal::~Animal() {
	cout << "Animal destructor called" << endl;
}