#include "Zombie.hpp"

int main(){
	Zombie *z = newZombie("Grand Emman");
	z->announce();
	randomChump("Frank");
	delete z;
	return (0);
}