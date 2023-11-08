
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	cout << this->_type << " constructor called" << endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	cout << "Cat copy constructor called" << endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
	cout << "Cat assignation operator called" << endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void Cat::makeSound() const {
	cout << "The " << this->_type << " does miaouuu!!" << endl;
}

Cat::~Cat() {
	cout << "Cat destructor called" << endl;
}