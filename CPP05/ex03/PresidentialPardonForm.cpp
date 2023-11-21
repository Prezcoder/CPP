
#include"PresidentialPardonForm.hpp"

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
		cout << _target << " has been pardoned by Zaphod Beeblebrox" << endl;
}

string PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a) {
	o << "PresidentialPardonForm name: " << a->getName() << endl;
	o << "PresidentialPardonForm target: " << a->getTarget() << endl;
	o << "PresidentialPardonForm grade required to sign: " << a->getGrade() << endl;
	o << "PresidentialPardonForm grade required to execute: " << a->getExecGrade() << endl;
	o << "PresidentialPardonForm signed: " << a->getSigned() << endl;
	return (o);
}