
#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	cout << "RobotomyRequestForm constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy)
{
	cout << "RobotomyRequestForm copy constructor called" << endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructor called" << endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	cout << "RobotomyRequestForm Assignation operator called" << endl;
	if (this == &copy)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
	{
		cout << "* drilling noises *" << endl;
		if (rand() % 2)
			cout << _target << " has been robotomized!" << endl;
		else
			cout << _target << " robotomization failed..." << endl;
	}
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "RobotomyRequestForm name: " << a->getName() << endl;
	o << "RobotomyRequestForm grade required to sign: " << a->getGrade() << endl;
	o << "RobotomyRequestForm grade required to execute: " << a->getExecGrade() << endl;
	o << "RobotomyRequestForm signed: " << a->getSigned() << endl;
	return (o);
}