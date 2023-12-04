
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

using std::cout;
using std::endl;
using std::stack;

template <typename T>
class MutantStack : public stack<T>
{
	public:
		MutantStack() : stack<T>() {}
		MutantStack(const MutantStack &copy) : stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &copy) {
			if (this != &copy)
				*this = copy;
			return (*this);
		}
		~MutantStack() {}

		typedef typename stack<T>::container_type::iterator iterator;
		iterator begin() { return (stack<T>::c.begin()); }
		iterator end() { return (stack<T>::c.end()); }
};

#endif