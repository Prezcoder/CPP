
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include<iostream>
#include"Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class AForm
{
	public:
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm(const string name, unsigned int grade, unsigned int execGrade);

		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;

		const string getName() const;
		int getGrade() const;
		int getExecGrade() const;
		bool getSigned() const;

		AForm &operator=(const AForm &copy);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const string _name;
		const int _grade;
		const int _execGrade;
		bool _signed;

		AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif