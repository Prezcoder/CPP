
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap frank("Frank");
	ScavTrap emman("Emman");
	FragTrap william("William");
	FragTrap john("John");
	cout << endl;
	
	//energy test
	// for (int i = 0; i < 50; i++) {
	// 	frank.attack("William");
	// 	frank.takeDamage(1);
	// 	frank.beRepaired(2);
	// }

	frank.guardGate();
	cout << endl;


	john.highFivesGuys();
	william.highFivesGuys();
	john.highFivesGuys();
	cout << endl;

	john.attack("William");
	john.takeDamage(1);
	john.beRepaired(2);
	william.attack("John");
	william.takeDamage(1);
	william.beRepaired(2);
	cout << endl;


	//hitpoint test
	frank.takeDamage(145);
	frank.beRepaired(10);
	frank.attack("William");
	frank.takeDamage(1);
	cout << endl;

	
	emman.guardGate();
	emman.guardGate();
	emman.takeDamage(568);
	emman.guardGate();
	return 0;
}