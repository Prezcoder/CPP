
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
cout << "----------------------------------------" << endl;
cout << j->getType() << " " << endl;
cout << i->getType() << " " << endl;
cout << "----------------------------------------" << endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
cout << "----------------------------------------" << endl;
const WrongAnimal *meta3 = new WrongAnimal();
const WrongAnimal *i3 = new WrongCat();
cout << "----------------------------------------" << endl;
cout << meta3->getType() << " " << endl;
cout << i3->getType() << " " << endl;
cout << "----------------------------------------" << endl;
meta3->makeSound();
i3->makeSound();

delete meta;
delete j;
delete i;
delete meta3;
delete i3;
return 0;
}