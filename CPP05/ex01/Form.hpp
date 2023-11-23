
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

using std::string;
using std::exception;
using std::cout;
using std::endl;

class Bureaucrat;

class Form
{
	private:
		const string _name;
		const int _grade;
		const int _execGrade;
		bool _signed;
		
	public:
		Form();
		Form(const Form &copy);
		~Form();

		Form(const string name, unsigned int grade, unsigned int execGrade);
		void beSigned(const Bureaucrat &b);

		const string getName() const;
		int getGrade() const;
		int getExecGrade() const;
		bool getSigned() const;

		Form &operator=(const Form &copy);

		exception GradeTooHighException() const;
		exception GradeTooLowException() const;

};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif