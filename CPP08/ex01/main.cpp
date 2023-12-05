
#include "Span.hpp"

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

int	main(void)
{
	printTitle("Test 1: Creating a Span");
	Span span = Span(5);
	try
	{ 
		span.addNumber(5);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		span.addNumber(22);
	}
	catch (std::exception &e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	cout << "List: " << span << endl;
	printTitle("Test 2: Shortest and longest span");
	try
	{
		cout << "Shortest span: " << span.shortestSpan() << endl;
		cout << "Longest span: " << span.longestSpan() << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	printTitle("Test 3: Adding a number to a full list");
	try
	{
		span.addNumber(11);
	}
	catch (std::exception &e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	printTitle("Test 4: Creating a Span with iterators");
	try 
	{
		list<int>	l(10000);
		std::srand(time(NULL));
		std::generate(l.begin(), l.end(), std::rand);
		Span span2(l.size());
		span2.addNumber(l.begin(), l.end());
		cout << "Shortest span: " << span2.shortestSpan() << endl;
		cout << "Longest span: " << span2.longestSpan() << endl;
	}
	catch ( std::exception& e ) 
	{
		cerr << "Error : " << e.what() << endl;
	}
	printTitle("Test 5: Copy constructor");
	Span span3 = Span(span);
	cout << "List: " << span3 << endl;
	printTitle("Test 6: Assignation operator");
	Span span4 = span;
	cout << "List: " << span4 << endl;
	printTitle("Test 7: Creating a Span with size of 0");
	try
	{
		Span span5 = Span(0);
		cout << "Longest span: " << span5.longestSpan() << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	printTitle("Test 8: Creating a Span with size of 1");
	try
	{
		Span span5 = Span(1);
		cout << "Shortest span: " << span5.shortestSpan() << endl;
	}
	catch (std::exception &e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	return (0);
}