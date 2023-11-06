
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const &point);
		Point(float const x, float const y);
		Point &operator=(Point const &point);
		Fixed getX() const;
		Fixed getY() const;
		~Point();

	private:
		Fixed const _x;
		Fixed const _y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif