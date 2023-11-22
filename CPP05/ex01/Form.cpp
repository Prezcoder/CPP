
#include "Form.hpp"

Form::Form() : _name("default"), _grade(150), _execGrade(150), _signed(false) {
	cout << "Form default constructor called" << endl;
}

Form::Form(const string name, unsigned int grade, unsigned int execGrade) : _name(name), _grade(grade), _execGrade(execGrade), _signed(false) {
	cout << "Form constructor called" << endl;
	if (grade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _grade(copy._grade), _execGrade(copy._execGrade), _signed(false) {
	cout << "Form copy constructor called" << endl;
	*this = copy;
}

Form::~Form() {
	cout << "Form destructor called" << endl;
}

Form &Form::operator=(const Form &copy) {
	cout << "Form assignation operator called" << endl;
	if (this == &copy)
	{
		return (*this);
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

int Form::getExecGrade() const {
	return (_execGrade);
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