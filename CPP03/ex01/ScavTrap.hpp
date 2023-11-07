
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const string &name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& copy);

		void	attack(std::string const& target);
		void	guardGate();

	private:
		ScavTrap();
		bool	_guardMode;

};

#endif