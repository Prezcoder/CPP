
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();
		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		ClapTrap();
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

};

#endif