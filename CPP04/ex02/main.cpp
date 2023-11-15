
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printTitle(const std::string& title) {
	std::cout << BLUE << "----------------------------------------" << std::endl;
	std::cout << GREEN << title << RESET << std::endl;
	std::cout << BLUE << "----------------------------------------" << RESET << std::endl;
}

int main() {
	// Test 1
	printTitle("Test 1: Animal Types");
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	// Test 2
	printTitle("Test 2: Animal Sounds");
	i->makeSound(); // will output the cat sound!
	j->makeSound();

	// Test 3
	printTitle("Test 3: Wrong Animal Types");
	const WrongAnimal* meta3 = new WrongAnimal();
	const WrongAnimal* i3 = new WrongCat();
	std::cout << meta3->getType() << " " << std::endl;
	std::cout << i3->getType() << " " << std::endl;

	// Test 4
	printTitle("Test 4: Wrong Animal Sounds");
	meta3->makeSound();
	i3->makeSound();

	// Test 5
	printTitle("Test 5: Cat's Brain Ideas");
	Cat cat;
	cat = Cat();
	std::cout << cat.getBrain()->getIdeas(7) << std::endl;

	// Test 6
	printTitle("Test 6: Animal Array");
	const AAnimal* animal_array[4];
	// Half filled with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();

	// Half filled with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();

	// Make them speak
	for (int i = 0; i < 4; i++)
		animal_array[i]->makeSound();

	// See if they are really dogs or cats
	for (int i = 0; i < 4; i++)
		std::cout << animal_array[i]->getType() << std::endl;

	// Delete them
	for (int i = 0; i < 4; i++)
		delete animal_array[i];

	// Cleanup
	delete j;
	delete i;
	delete meta3;
	delete i3;

	return 0;
}
