
#include "Harl.hpp"

Harl::Harl()
{
	cout << "Harl as arrived!!" << endl;
}

Harl::~Harl()
{
	cout << "Harl is gone !" << endl;
}

void Harl::debug( void )
{
	cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void Harl::info( void )
{
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money." << endl;
	cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void Harl::warning( void )
{
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free." << endl;
	cout << "I’ve been coming here for years and you just started working here last month." << endl;
}

void Harl::error( void )
{
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable, I want to speak to the manager now." << endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*fonctions[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	string s[4] = { "debug", "info", "warning", "error" };
	for (int i = 0; i < 4; i++)
	{
		if (s[i] == level)
		{
			(this->*fonctions[i])();
			return ;
		}
	}
}