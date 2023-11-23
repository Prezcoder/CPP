
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::exception;
using std::cout;
using std::endl;

class Bureaucrat;

class AForm
{
	private:
		const string _name;
		const int _grade;
		const int _execGrade;
		bool _signed;
		AForm();

	public:
		AForm(const AForm &copy);
		AForm(const string name, unsigned int grade, unsigned int execGrade);
		virtual ~AForm();

		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;

		const string getName() const;
		int getGrade() const;
		int getExecGrade() const;
		bool getSigned() const;

		AForm &operator=(const AForm &copy);

		exception GradeTooHighException() const;
		exception GradeTooLowException() const;
		exception NotSignedException() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif