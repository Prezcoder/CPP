
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	cout << this->_type << " constructor called" << endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	cout << "Cat copy constructor called" << endl;
	this->_brain = new Brain(*copy._brain);
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

Brain *Cat::getBrain() const {
	return (this->_brain);
}

Cat::~Cat() {
	delete this->_brain;
	cout << "Cat destructor called" << endl;
}