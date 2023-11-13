
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal") {
	cout << "AAnimal default constructor called" << endl;
}

AAnimal::AAnimal(string type) : _type(type) {
	cout << "AAnimal " << this->_type << " constructor called" << endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	cout << "AAnimal copy constructor called" << endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	cout << "AAnimal assignation operator called" << endl;
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
	cout << "AAnimal destructor called" << endl;
}