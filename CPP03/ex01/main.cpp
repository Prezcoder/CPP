
#include "ScavTrap.hpp"

int main()
{
	ScavTrap frank("Frank");
	ScavTrap emman("Emman");
	
	//energy test
	// for (int i = 0; i < 50; i++) {
	// 	frank.attack("William");
	// 	frank.takeDamage(1);
	// 	frank.beRepaired(2);
	// }

	frank.guardGate();

	//hitpoint test
	frank.takeDamage(145);
	frank.beRepaired(10);
	frank.attack("William");
	frank.takeDamage(1);
	
	emman.guardGate();
	emman.guardGate();
	emman.takeDamage(568);
	emman.guardGate();
	return 0;
}