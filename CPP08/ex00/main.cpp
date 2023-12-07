
#include "easyfind.hpp"
#include "main.h"

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
	printTitle("Test 1: Vector");
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		cout << *easyfind(v, 5) << endl;
		cout << *easyfind(v, 10) << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Not found" << endl;
	}
	printTitle("Test 2: List");
	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	try
	{
		cout << *easyfind(l, 5) << endl;
		cout << *easyfind(l, 10) << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Not found" << endl;
	}
	printTitle("Test 3: deque");
	std::deque<int> e;
	for (int i = 0; i < 10; i++)
		e.push_back(i);
	try
	{
		cout << *easyfind(e, 5) << endl;
		cout << *easyfind(e, 10) << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Not found" << endl;
	}
	return 0;
}