#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "==> Shrubbery Creation Form <==" << std::endl;
    try{
        Bureaucrat theKnightsWhoSayNi("The Knights who say NI", 137);
        ShrubberyCreationForm shrubbery("roger_the_Shrubber");
        std::cout << theKnightsWhoSayNi << std::endl;
        std::cout << shrubbery << std::endl;
        theKnightsWhoSayNi.signForm(shrubbery);
        theKnightsWhoSayNi.executeForm(shrubbery);
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Robotomy Request Form <==" << std::endl;
    try {
        Bureaucrat vogons("The Vogons", 40);
        RobotomyRequestForm robot("Marvin");
        std::cout << vogons << std::endl;
        std::cout << robot << std::endl;
        vogons.signForm(robot);
        vogons.executeForm(robot);
        vogons.executeForm(robot); //try again for =/= result
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Presidential Pardon Form <==" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Execute Without Signing <==" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 1);
        ShrubberyCreationForm shrubby("garden");
        
        charlie.executeForm(shrubby);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Grade Too Low to Execute <==" << std::endl;
    try {
        Bureaucrat lowGrade("Low Grade", 100);
        Bureaucrat highGrade("High Grade", 1);
        PresidentialPardonForm pardonTheII("Ford Prefect");
        
        highGrade.signForm(pardonTheII);
        lowGrade.executeForm(pardonTheII);  // Grade too low!
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Grade Too Low to Sign <==" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm mrroboto("Marvin");
        
        intern.signForm(mrroboto);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
