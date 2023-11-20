
#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"Intern.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printTitle(const std::string& title) {
	std::cout << BLUE << "----------------------------------------" << std::endl;
	std::cout << GREEN << title << RESET << std::endl;
	std::cout << BLUE << "----------------------------------------" << RESET << std::endl;
}

int main()
{
	printTitle("Test 1: Init Bureaucrat");
	Bureaucrat Leon("Leon", 1);
	Bureaucrat Arthur("Arthur", 150);
	try{
		Bureaucrat Smith("Smith", 151);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Bureaucrat Nicole("Nicole", 0);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	Bureaucrat Jeannine("Jeannine", 42);
	printTitle("Test 1: Bureaucrat initiated 3 out of 5 try");
	cout << endl;
	cout << Leon << endl;
	cout << Arthur << endl;
	cout << Jeannine << endl;
	printTitle("Test 2: Try to increment/decrement Bureaucrat");
	
	try{
		Leon.incrementGrade();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.decrementGrade();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Jeannine.incrementGrade();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << Leon << endl;
	cout << Arthur << endl;
	cout << Jeannine << endl;
	printTitle("Test 3: Init Form");
	PresidentialPardonForm form("Form1");
	printTitle("Test 3: Form initiated");
	cout << form << endl;
	printTitle("Test 4: Try to sign Form");
	try{
		Leon.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form << endl;
	printTitle("Test 5: Try presidential pardon");
	try{
		Leon.executeForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.executeForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	printTitle("Test 6: Init RobotomyRequestForm");
	RobotomyRequestForm form2("Form2");
	printTitle("Test 6: RobotomyRequestForm initiated");
	cout << form2 << endl;
	printTitle("Test 7: Try to sign RobotomyRequestForm");
	try{
		Leon.signForm(form2);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.signForm(form2);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form2 << endl;
	printTitle("Test 8: Try robotomy request");
	try{
		Leon.executeForm(form2);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.executeForm(form2);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	printTitle("Test 9: Init ShrubberyCreationForm");
	ShrubberyCreationForm form3("Form3");
	printTitle("Test 9: ShrubberyCreationForm initiated");
	cout << form3 << endl;
	printTitle("Test 10: Try to sign ShrubberyCreationForm");
	try{
		Leon.signForm(form3);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.signForm(form3);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form3 << endl;
	printTitle("Test 11: Try shrubbery creation");
	try{
		Leon.executeForm(form3);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Arthur.executeForm(form3);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	printTitle("Test 12: Init Intern");
	Intern intern;
	printTitle("Test 13: Try to make forms");
	AForm *form4 = intern.makeForm("presidential pardon", "Form4");
	AForm *form5 = intern.makeForm("robotomy request", "Form5");
	AForm *form6 = intern.makeForm("shrubbery creation", "Form6");
	cout << *form4 << endl;
	cout << *form5 << endl;
	cout << *form6 << endl;
	printTitle("Test 14: Try to sign forms");
	try{
		Leon.signForm(*form4);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Leon.signForm(*form5);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Leon.signForm(*form6);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << *form4 << endl;
	cout << *form5 << endl;
	cout << *form6 << endl;
	printTitle("Test 15: Try to execute forms");
	try{
		Leon.executeForm(*form4);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Leon.executeForm(*form5);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Leon.executeForm(*form6);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	printTitle("Test 16: Delete forms");
	delete form4;
	delete form5;
	delete form6;

	cout << endl;
	cout << endl;

	return (0);
}