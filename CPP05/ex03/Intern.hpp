
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern &copy);

		~Intern();

		Intern &operator=(const Intern &copy);

		AForm *makeForm(const string form, const string target);
};