
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
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
cout << "----------------------------------------" << endl;
Cat cat;
cout << cat.getBrain()->getIdeas(7) << endl;
cout << "----------------------------------------" << endl;

const Animal	*animal_array[4];
cout << endl;
// Half filled with dogs
for (int i = 0; i < 2; i++)
	animal_array[i] = new Dog();
cout << endl;
// Half filled with cats
for (int i = 2; i < 4; i++)
	animal_array[i] = new Cat();
cout << endl;

// Make them speak
for (int i = 0; i < 4; i++)
	animal_array[i]->makeSound();
cout << endl;

// See if they are really dogs or cats
for (int i = 0; i < 4; i++)
	cout << animal_array[i]->getType() << endl;
cout << endl;

// Delete them
for (int i = 0; i < 4; i++)
	delete animal_array[i];
cout << endl;

delete meta;
delete j;
delete i;
delete meta3;
delete i3;
return 0;
}