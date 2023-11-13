
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	cout << this->_type << " constructor called" << endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	cout << "Dog copy constructor called" << endl;
	this->_brain = new Brain(*copy._brain);
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
	cout << "Dog assignation operator called" << endl;
	if (this->_brain)
		delete this->_brain;
	if (this != &copy)
	{
		_type = copy._type;
		_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void Dog::makeSound() const {
	cout << "The " << this->_type << " barks!" << endl;
}

Brain *Dog::getBrain() const {
	return (this->_brain);
}

Dog::~Dog() {
	delete this->_brain;
	cout << "Dog destructor called" << endl;
}