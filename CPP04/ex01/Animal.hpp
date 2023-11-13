
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal
{
	public:
		Animal();
		Animal(string type);
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &copy);

		virtual void makeSound() const;

		virtual string getType() const;

	protected:
		string _type;

};

#endif