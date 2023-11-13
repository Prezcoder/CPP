#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	cout << this->_type << " constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	cout << "WrongCat copy constructor called" << endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	cout << "WrongCat assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void WrongCat::makeSound() const {
	cout << this->_type << " wrong miaouuu!!" << endl;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called" << endl;
}