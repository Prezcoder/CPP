
#include "easyfind.hpp"

int main()
{
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
		cout << "Not found" << endl;
	}
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
		cout << "Not found" << endl;
	}
	std::array<string, 5> s;
	for (int i = 0; i < 5; i++)
		s.fill("jambon");
		try
	{
		cout << s[2] << endl;
		if (cout << s[6])
			throw std::invalid_argument("No jambon");
	}
	catch (std::exception &e)
	{
		cout << "Not found" << endl;
	}
	return 0;
}