
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
	public:
		Form();
		Form(const Form &copy);
		~Form();

		Form(const string name, unsigned int grade);
		void beSigned(const Bureaucrat &b);

		const string getName() const;
		int getGrade() const;
		bool getSigned() const;

		Form &operator=(const Form &copy);

		exception GradeTooHighException() const;
		exception GradeTooLowException() const;

		private:
			const string _name;
			const int _grade;
			bool _signed;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif