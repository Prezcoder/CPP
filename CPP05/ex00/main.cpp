
#include"Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Bureaucrat b3("b3", 151);
    Bureaucrat b4("b4", 0);
    Bureaucrat b5("b5", 42);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;

    try{
        b1.incrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        b2.decrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        b3.incrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        b4.decrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        b5.incrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }


    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;

    return (0);
}