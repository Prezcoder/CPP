
#include"ShrubberyCreationForm.hpp"

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

string ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	o << "ShrubberyCreationForm name: " << a->getName() << endl;
	o << "ShrubberyCreationForm target: " << a->getTarget() << endl;
	o << "ShrubberyCreationForm grade required to sign: " << a->getGrade() << endl;
	o << "ShrubberyCreationForm grade required to execute: " << a->getExecGrade() << endl;
	o << "ShrubberyCreationForm signed: " << a->getSigned() << endl;
	return (o);
}