
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
using std::string;
using std::cout;
using std::endl;

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
		unsigned int getGrade() const;

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