#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Brain
{
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &copy);
	string getIdeas(int i) const;

private:
	string *_ideas;

};

#endif