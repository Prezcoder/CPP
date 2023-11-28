
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	cout << "ShrubberyCreationForm constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy) {
	cout << "ShrubberyCreationForm copy constructor called" << endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	cout << "ShrubberyCreationForm destructor called" << endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	cout << "ShrubberyCreationForm Assignation operator called" << endl;
	if (this == &copy)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
	{
		std::ofstream file;
		file.open((_target + "_shrubbery").c_str());
		file << "       *      " << endl;
		file << "      / \\      " << endl;
		file << "     /\\ *\\     " << endl;
		file << "    /\\O \\*\\    " << endl;
		file << "   /*/\\/ \\/\\   " << endl;
		file << "  /\\O\\/ \\*\\/\\  " << endl;
		file << " /\\*\\/ \\*\\/\\/\\ " << endl;
		file << "/\\O\\/ \\/*/\\/O/\\" << endl;
		file << "      | |      " << endl;
		file << "      | |      " << endl;
		file << "      | |      " << endl;
		file << endl;
		file.close();
	}
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}
