
#include"Intern.hpp"

Intern::Intern() {
	cout << "Intern default constructor called" << endl;
}

Intern::Intern(const Intern &copy) {
	cout << "Intern copy constructor called" << endl;
	*this = copy;
}

Intern::~Intern() {
	cout << "Intern destructor called" << endl;
}

Intern &Intern::operator=(const Intern &copy) {
	cout << "Intern assignation operator called" << endl;
	if (this != &copy)
	{
		(void)copy;
	}
	return (*this);
}

AForm *Intern::makeForm(string name, string target) {
	string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *forms[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			cout << "Intern creates " << name << endl;
			return (forms[i]);
		}
	}
	cout << "Intern could not create " << name << endl;
	return (NULL);
}