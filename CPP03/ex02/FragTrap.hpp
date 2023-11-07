#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const string &name);
		FragTrap(const FragTrap& copy);
		~FragTrap();

		FragTrap& operator=(const FragTrap& copy);

		void	highFivesGuys(void);

	private:
		FragTrap();
		bool	_highFivesMode;

};

#endif