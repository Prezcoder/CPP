
#include<iostream>

using std::cout;
using std::endl;

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
	else
		cout << "Unknown" << endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		cout << "A" << endl;
	}
	catch (std::bad_cast& e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		cout << "B" << endl;
	}
	catch (std::bad_cast& e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		cout << "C" << endl;
	}
	catch (std::bad_cast& e) {}
}

int main()
{
	srand(time(NULL));
	Base*   a = generate();
	Base*   b = generate();
	Base*   c = generate();
	Base*   d = generate();

	std::cout << "a* = "; identify( a );
	std::cout << "a& = "; identify( *a ); std::cout << std::endl;

	std::cout << "b* = "; identify( b );
	std::cout << "b& = "; identify( *b ); std::cout << std::endl;

	std::cout << "c* = "; identify( c );
	std::cout << "c& = "; identify( *c ); std::cout << std::endl;

	std::cout << "d* = "; identify( d );
	std::cout << "d& = "; identify( *d ); std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}