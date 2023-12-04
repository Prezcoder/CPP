
#include "MutantStack.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

void printTitle(const std::string& title) {
	std::cout << YELLOW << "----------------------------------------" << std::endl;
	std::cout << GREEN << title << RESET << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET << std::endl;
}

int	main()
{
	printTitle("Test 1: Creating a MutantStack");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "List: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	printTitle("Test 2: Creating a copy MutantStack with iterators");
	MutantStack<int> mstack2(mstack);
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	++it2;
	--it2;
	std::cout << "List: ";
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	printTitle("Test 3: Assigning a MutantStack");
	MutantStack<int> mstack3 = mstack;
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	++it3;
	--it3;
	std::cout << "List: ";
	while (it3 != ite3)
	{
		std::cout << *it3 << " ";
		++it3;
	}
	std::cout << std::endl;
	printTitle("Test 4: Creating a list to compare with the MutantStack");
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "Top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "Size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::const_iterator it4 = list.begin();
	std::list<int>::const_iterator ite4 = list.end();
	std::cout << "List: ";
	while (it4 != ite4)
	{
		std::cout << *it4 << " ";
		++it4;
	}
	std::cout << std::endl;
}