
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::string;
using std::cout;
using std::endl;

class Bureaucrat;

class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		const string _target;
		RobotomyRequestForm(void);
		
	public:
		RobotomyRequestForm(string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);

		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		void execute(Bureaucrat const &executor)const;

		string getTarget(void)const;
};

#endif