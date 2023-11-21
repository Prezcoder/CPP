
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const string name, unsigned int grade) : _name(name), _grade(grade)
{
	cout << "Bureaucrat constructor called" << endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	cout << "Bureaucrat copy constructor called" << endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	cout << "Bureaucrat assignation operator called" << endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return (*this);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form &f) const
{
	if (f.getSigned() == true)
	{
		cout << _name << " cannot sign " << f.getName() << " because it's already signed" << endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
		cout << _name << " signs " << f.getName() << endl;
	}
	catch (std::exception &e)
	{
		cout << _name << " cannot sign " << f.getName() << " because " << e.what() << endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << endl;
	return (out);
}

const string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor called" << endl;
}

exception Bureaucrat::GradeTooHighException() const {
	throw std::invalid_argument("Grade too high");
}

exception Bureaucrat::GradeTooLowException() const {
	throw std::invalid_argument("Grade too low");
}