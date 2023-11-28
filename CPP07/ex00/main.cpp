
#include <iostream>
#include "Whatever.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printTitle(const std::string& title) {
	std::cout << BLUE << "----------------------------------------" << std::endl;
	std::cout << GREEN << title << RESET << std::endl;
	std::cout << BLUE << "----------------------------------------" << RESET << std::endl;
}

int main( void ) {
	printTitle("Test 1: Interger");
	int a = 2;
	int b = 3;
	::swap( a, b );
	cout << "a = " << a << ", b = " << b << endl;
	cout << "min( a, b ) = " << ::min( a, b ) << endl;
	cout << "max( a, b ) = " << ::max( a, b ) << endl;

	printTitle("Test 3: Strings");
	string c = "chaine1";
	string d = "chaine2";
	::swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "min( c, d ) = " << ::min( c, d ) << endl;
	cout << "max( c, d ) = " << ::max( c, d ) << endl;

	printTitle("Test 2: Float");
	float e = 42.42;
	float f = 21.21;
	::swap(e, f);
	cout << "e = " << e << ", f = " << f << endl;
	cout << "min( e, f ) = " << ::min( e, f ) << endl;
	cout << "max( e, f ) = " << ::max( e, f ) << endl;

	return 0;
}