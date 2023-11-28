
#include <iostream>
#include "Iter.hpp"

int main( void ) {
	int intArray[] = { 1, 2, 3, 4, 5 };
	float floatArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	string stringArray[] = { "one", "two", "three", "four", "five" };

	cout << "intArray: " << endl;
	iter(intArray, 5, print);
	cout << endl;

	cout << "floatArray: " << endl;
	iter(floatArray, 5, print);
	cout << endl;

	cout << "stringArray: " << endl;
	iter(stringArray, 5, print);
	cout << std::endl;

	return 0;

}