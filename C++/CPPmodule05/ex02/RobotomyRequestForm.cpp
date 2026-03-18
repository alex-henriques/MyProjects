#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", SIGN_GRADE, EXEC_GRADE), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::executeAction() const {
    std::cout << "* WHIRRRRRRRRRR.....DRILLING NOISES *" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been robotomised successfully" << std::endl;
    } else {
        std::cout << target << " Robotomisation failed..." << std::endl;
    }
}