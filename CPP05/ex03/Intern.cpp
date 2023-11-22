
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

static AForm *makePresident(const std::string target) {
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(string name, string target) {
	string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(*forms[])(const string target) = {&makePresident, &makeRobot, &makeShrubbery};
	
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			cout << "Intern creates " << name << endl;
			return (forms[i](target));
		}
	}
	throw NoFormFoundException();
}

exception Intern::NoFormFoundException() const {
	throw std::invalid_argument("No form found");
}