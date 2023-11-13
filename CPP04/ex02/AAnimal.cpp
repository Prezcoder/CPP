
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal") {
	cout << "Animal default constructor called" << endl;
}

AAnimal::AAnimal(string type) : _type(type) {
	cout << "Animal " << this->_type << " constructor called" << endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	cout << "Animal copy constructor called" << endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	cout << "Animal assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void AAnimal::makeSound() const {
	cout << "Generic animal sound..." << endl;
}

string AAnimal::getType() const {
	return (this->_type);
}

AAnimal::~AAnimal() {
	cout << "Animal destructor called" << endl;
}