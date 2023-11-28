
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	cout << "PresidentialPardonForm constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy) {
	cout << "PresidentialPardonForm copy constructor called" << endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << "PresidentialPardonForm destructor called" << endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	cout << "PresidentialPardonForm Assignation operator called" << endl;
	if (this == &copy)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
		cout << _target << " has been pardoned by Zafod Beeblebrox" << endl;
}

string PresidentialPardonForm::getTarget(void) const {
	return (_target);
}
