#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    std::cout << "==> Intern creates valid forms <==" << std::endl;
     {
        Intern intern;
        AForm* form1;
        AForm* form2;
        AForm* form3;

        try {
            form1 = intern.makeForm("shrubbery creation", "home");
            std::cout << *form1 << std::endl;
            delete form1;
            std::cout << std::endl;

            form2 = intern.makeForm("robotomy request", "Bender");
            std::cout << *form2 << std::endl;
            delete form2;
            std::cout << std::endl;

            form3 = intern.makeForm("presidential pardon", "Arthur");
            std::cout << *form3 << std::endl;
            delete form3;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "==> Invalid form name <==" << std::endl;
    {
        Intern intern;
        AForm* form;

        try {
            form = intern.makeForm("tax evasion form", "DaffyDuck");
            std::cout << *form << std::endl;
            delete form;
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "==> Multiple forms same intern <==" << std::endl;
    {
        Intern intern;
        Bureaucrat alice("Alice", 1);
        AForm* forms[3];
        try {
            forms[0] = intern.makeForm("shrubbery creation", "forest");
            forms[1] = intern.makeForm("robotomy request", "Marvin");
            forms[2] = intern.makeForm("presidential pardon", "Zaphod");
            for (int i = 0; i < 3; i++) {
                std::cout << *forms[i] << std::endl;
                alice.signForm(*forms[i]);
                alice.executeForm(*forms[i]);
                std::cout << std::endl;
            }
            for (int i = 0; i < 3; i++) {
                delete forms[i];
            }
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "==> Intern with low grade bureaucrat <==" << std::endl;
    {
        Intern intern;
        Bureaucrat lowly("Lowly", 150);
        AForm* form;

        try {
            form = intern.makeForm("robotomy request", "Target");
            std::cout << *form << std::endl;
            lowly.signForm(*form);  // will fail
            lowly.executeForm(*form);  // willfail
            delete form;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}