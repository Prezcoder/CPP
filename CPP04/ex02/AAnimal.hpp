
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
	public:
		AAnimal();
		AAnimal(string type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &copy);

		virtual void makeSound() const = 0;

		virtual string getType() const;

	protected:
		string _type;

};

#endif