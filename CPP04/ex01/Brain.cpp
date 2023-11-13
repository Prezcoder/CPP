
#include "Brain.hpp"

Brain::Brain() : _ideas(nullptr) {
	this->_ideas = new string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Brainzzz!";
	cout << "Brain as been constructed and filled with ideas." << endl;
}

Brain::Brain(const Brain &copy) {
	this->_ideas = new string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	cout << "Brain as been constructed and filled with ideas." << endl;
}

Brain &Brain::operator=(const Brain &copy) {
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

string Brain::getIdeas(int i) const {
	return (this->_ideas[i]);
}

Brain::~Brain() {
	delete [] this->_ideas;
	cout << "Brain as been destroyed." << endl;
}