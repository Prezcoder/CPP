#include "Zombie.hpp"

int main(){
	int size(20);

	Zombie *zombies = zombieHorde(size, "Frank");
	for (int i(0); i < size; i++)
		zombies[i].announce();
	delete []	zombies;
	return (0);
}