
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	// std::cout << "Float constructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
	{
		(Fixed)this->_x = point._x;
		(Fixed)this->_y = point._y;
	}
	return *this;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed const ab = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed const bc = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed const ca = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	return (ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0);
}