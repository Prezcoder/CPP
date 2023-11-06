

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;


std::cout << Fixed::min( a, b ) << std::endl;
std::cout << --a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;

a = 5;

if (b == b)
	cout << "b == b" << endl;
else
	cout << "b != b" << endl;
if (a > b)
	cout << "a > b" << endl;
else
	cout << "a <= b" << endl;

a = 7;

if (a != b)
	cout << "a != b" << endl;
else
	cout << "a == b" << endl;
if (a < b)
	cout << "a < b" << endl;
else
	cout << "a >= b" << endl;

cout << "b = " << b << endl;
Fixed result = a + b;
cout << result << endl;
result = a - b;
cout << result << endl;
result = a * b;
cout << result << endl;
result = a / b;
cout << result << endl;

return 0;
}