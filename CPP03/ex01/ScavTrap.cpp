
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "Default ScavTrap just arrived!" << endl;
} 

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy), _guardMode(false) {
	cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap::ScavTrap(const string &name ) : ClapTrap(name), _guardMode(false) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "ScavTrap " << name << " just arrived!" << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	cout << "ScavTrap assignation operator called" << endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap " << this->_name << " is destroyed!"<< endl;
}

void ScavTrap::attack(std::string const& target) {
	if (this->_energyPoints <= 0 && this->_hitPoints > 0)
	{
		cout << "ScavTrap " << this->_name << " has no energy points!" << endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " is dead and can't attack!" << endl;
		return ;
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
		this->_energyPoints -= 1;
	}
}

void ScavTrap::guardGate() {
	if (this->_hitPoints == 0)
		cout << "ScavTrap " << this->_name << " is dead and can't Gate keep!" << endl;
	else if (this->_energyPoints == 0)
		cout << "ScavTrap " << this->_name << " has no energy points!" << endl;
	else if (this->_guardMode == true)
		cout << "ScavTrap " << this->_name << " is already in Gate keeper mode." << endl;
	else
	{
		cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << endl;
		this->_guardMode = true;
	}
}
