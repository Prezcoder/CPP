
#include"Bureaucrat.hpp"
#include"Form.hpp"

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
	Form form("form", 42, 42);
	cout << form << endl;
	printTitle("Test 4: Try to sign Form");
	try{
		Arthur.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Leon.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	try{
		Jeannine.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form << endl;
	printTitle("Test 5: Try to sign Form");
	Form form2("form2", 1, 42);
	cout << form2 << endl;
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
	try{
		Jeannine.signForm(form2);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form2 << endl;

	return (0);
}