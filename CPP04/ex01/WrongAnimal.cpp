
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::WrongAnimal(string type) : _type(type) {
	cout << "WrongAnimal " << this->_type << " constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	cout << "WrongAnimal copy constructor called" << endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	cout << "WrongAnimal assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	cout << "This sound is so wrong..." << endl;
}

string WrongAnimal::getType() const {
	return (this->_type);
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal destructor called" << endl;
}