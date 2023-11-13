#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(string type);
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &copy);

		string getType() const;
		void makeSound() const;

	protected:
		string _type;

};

#endif