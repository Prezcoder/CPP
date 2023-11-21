
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include"Form.hpp"
using std::string;
using std::cout;
using std::endl;

class Form;

class Bureaucrat
{
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

private:
	const string _name;
	int _grade;


};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif