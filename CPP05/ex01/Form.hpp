
#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include"Bureaucrat.hpp"
using std::string;
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

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
	};

	private:
		const string _name;
		const int _grade;
		bool _signed;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif