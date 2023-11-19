
#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
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

	cout << Leon << endl;
	cout << Arthur << endl;
	cout << Jeannine << endl;

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

	Form form("form", 42);
	cout << form << endl;
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
	try{
		Jeannine.signForm(form);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
	cout << form << endl;
	Form form2("form2", 1);
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