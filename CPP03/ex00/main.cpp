
#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Fred");

	claptrap.attack("Gros Jambon");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(5);
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.attack("Gros Jambon");
	claptrap.beRepaired(3);
	claptrap.attack("Gros Jambon");
	claptrap.takeDamage(5);

	return (0);
}