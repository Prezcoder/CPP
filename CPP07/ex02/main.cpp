
#include "Array.hpp"

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

int main()
{
	printTitle("Test 1: Interger");
	Array<int> a(5);
	Array<int> b(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i + 5;

	cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	cout << endl;

	printTitle("Test 2: Copy");
	cout << "a = b" << endl;
	a = b;

	cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	cout << endl;

	cout << "a[0] = 42" << endl;
	a[0] = 42;

	cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	cout << endl;
	printTitle("Test 3: Out of range");
	cout << "a[5] = 42" << endl;
	try
	{
		a[5] = 42;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	cout << endl;
	printTitle("Test 4: String");
	Array<string> c(3);
	c[0] = "Hello";
	c[1] = "World";
	c[2] = "!";
	cout << "c: ";
	for (unsigned int i = 0; i < c.size(); i++)
		cout << c[i] << " ";
	cout << endl;
	return 0;
}
