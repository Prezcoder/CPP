
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() , _highFivesMode(false) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "Default FragTrap " << _name << " is born!" << endl;
}

FragTrap::FragTrap(const string &name) : ClapTrap(name) , _highFivesMode(false) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "FragTrap " << _name << " is born!" << endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy), _highFivesMode(false) {
	cout << "FragTrap copy constructor called" << endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	cout << "FragTrap assignation operator called" << endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	if (this->_hitPoints == 0)
		cout << "FragTrap " << this->_name << " is dead and can't high fives!" << endl;
	else if (this->_energyPoints == 0)
		cout << "FragTrap " << this->_name << " has no energy points to high fives!" << endl;
	else if (this->_highFivesMode == true)
		cout << "FragTrap " << this->_name << " is already waiting to high fives!" << endl;
	else
	{
		cout << "FragTrap " << this->_name << " want's to high fives!" << endl;
		this->_highFivesMode = true;
	}
}



FragTrap::~FragTrap() {
	cout << "FragTrap " << _name << " is destroyed!" << endl;
}