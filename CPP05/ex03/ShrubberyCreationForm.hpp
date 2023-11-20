
#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
		const string _target;
		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);

		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		void execute(Bureaucrat const &executor)const;

		string getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
