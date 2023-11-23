
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		const string _target;
		PresidentialPardonForm(void);
		
	public:
		PresidentialPardonForm(string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		void execute(Bureaucrat const &executor)const;

		string getTarget(void)const;
};

#endif