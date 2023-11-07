
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	cout << "Default constructor just arrived!" << endl;
}
 
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	cout << "ClapTrap " << name << " just arrived!" << endl;

}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	cout << "ClapTrap copy constructor called" << endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap " << _name << " is destroyed" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	cout << "ClapTrap assignation operator called" << endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const& target) {
	if (this->_energyPoints <= 0 && this->_hitPoints > 0)
	{
		cout << "ClapTrap " << this->_name << " has no energy points!" << endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " is dead and can't attack!" << endl;
		return ;
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
		this->_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= amount)
	{
		cout << "ClapTrap " << this->_name << " is dead!" << endl;
		this->_hitPoints = 0;
		return ;
	}
	cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= amount && this->_hitPoints > 0)
	{
		cout << "ClapTrap " << this->_name << " is out of energy!" << endl;
		return ;
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << endl;
		_energyPoints -= 1;
		this->_hitPoints += amount;
		if (this->_hitPoints > 10)
			this->_hitPoints = 10;
	}
}

