
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

using std::exception;
using std::string;
using std::cout;
using std::endl;

class Form;

class Bureaucrat
{
	private:
		const string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat(const string name, unsigned int grade);

		void incrementGrade();
		void decrementGrade();
		const string getName() const;
		int getGrade() const;
		void signForm(Form &f) const;

		Bureaucrat &operator=(const Bureaucrat &copy);

		exception GradeTooHighException() const;
		exception GradeTooLowException() const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif