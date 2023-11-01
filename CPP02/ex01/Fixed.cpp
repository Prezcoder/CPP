
#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	cout << "Default constructor called" << endl;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
	cout << "Copy constructor called" << endl;
	*this = fixed;
}

Fixed::Fixed(int const value) : _fixedPointValue(value << this->_fractionBits) {
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(float const value) : _fixedPointValue(roundf(value * (1 << this->_fractionBits))) {
	cout << "Float constructor called" << endl;
}

float Fixed::toFloat( void ) const {
	return (float)this->_fixedPointValue / (1 << this->_fractionBits);
}

int Fixed::toInt( void ) const {
	return this->_fixedPointValue >> this->_fractionBits;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	cout << "Copy assignment operator called" << endl;
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return *this;
}

ostream &operator<<(ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}