
#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade(150), _execGrade(150), _signed(false) {
	cout << "AForm default constructor called" << endl;
}

AForm::AForm(const string name, unsigned int grade, unsigned int execGrade) : _name(name), _grade(grade),  _execGrade(execGrade), _signed(false) {
	cout << "AForm constructor called" << endl;
	if (grade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _grade(copy._grade), _execGrade(copy._execGrade), _signed(false) {
	cout << "AForm copy constructor called" << endl;
}

AForm::~AForm() {
	cout << "AForm destructor called" << endl;
}

AForm &AForm::operator=(const AForm &copy) {
	cout << "AForm assignation operator called" << endl;
	if (this == &copy)
	{
		return (*this);
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _grade)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const string AForm::getName() const {
	return (_name);
}

int AForm::getGrade() const {
	return (_grade);
}

int AForm::getExecGrade() const {
	return (_execGrade);
}

bool AForm::getSigned() const {
	return (_signed);
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << f.getName() << ", Aform grade " << f.getGrade() << ", signed: " << f.getSigned() << "." << endl;
	return (out);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("Form not signed");
}