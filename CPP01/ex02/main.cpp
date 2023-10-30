
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string brain("HI THIS IS BRAIN");

	string* stringPTR = &brain;
	string& stringREF = brain;

	cout << "brain address :" << &brain << endl;
	cout << "stringPTR address :" << &stringPTR << endl;
	cout << "stringREF address :" << &stringREF << endl;

	cout << endl;
	cout << "What's inside brain? :" << brain << endl;
	cout << "What's inside stringPTR? :" << *stringPTR << endl;
	cout << "What's inside stringREF? :" << stringREF << endl;

	cout << endl;
	cout << "Let's change brain..." << endl;
	brain = "HI THIS BRAIN IS DEAD";
	cout << "What's inside brain now? :" << brain << endl;

	cout << endl;
	cout << "Let's change stringPTR..." << endl;
	*stringPTR = "HI THIS BRAIN WANT'S TO EAT";
	cout << "What's inside brain now? :" << brain << endl;

	cout << endl;
	cout << "Let's change stringREF..." << endl;
	stringREF = "HI THIS BRAIN WANT'S TO DIE";
	cout << "What's inside brain now? :" << brain << endl;
}