
#include "Form.hpp"

Form::Form() : _name("default"), _grade(150), _signed(false) {
	cout << "Form default constructor called" << endl;
}

Form::Form(const string name, unsigned int grade) : _name(name), _grade(grade), _signed(false) {
	cout << "Form constructor called" << endl;
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _grade(copy._grade), _signed(copy._signed) {
	cout << "Form copy constructor called" << endl;
	*this = copy;
}

Form::~Form() {
	cout << "Form destructor called" << endl;
}

Form &Form::operator=(const Form &copy) {
	cout << "Form assignation operator called" << endl;
	if (this != &copy)
	{
		_signed = copy._signed;
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _grade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const string Form::getName() const {
	return (_name);
}

int Form::getGrade() const {
	return (_grade);
}

bool Form::getSigned() const {
	return (_signed);
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << f.getName() << ", form grade " << f.getGrade() << ", signed: " << f.getSigned() << "." << endl;
	return (out);
}

exception Form::GradeTooHighException() const {
	throw std::invalid_argument("Grade too high");
}

exception Form::GradeTooLowException() const {
	throw std::invalid_argument("Grade too low");
}