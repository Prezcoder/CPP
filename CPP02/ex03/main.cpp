
#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	Point point(1, 1);

	if (bsp(a, b, c, point))
		cout << "Point is inside the triangle" << endl;
	else
		cout << "Point is outside the triangle" << endl;

return 0;
}